import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plot

import pandas as pd

# （1）定义手写数字数据获取类，用于下载数据和随机获取小批量训练数据
class MNISTLoader():
    def __init__(self):
        minist = tf.keras.datasets.mnist
        # 训练数据x_train, 正确值y_train，测试数据x_test，测试数据正确值self.y_test
        (self.x_train, self.y_train), (self.x_test, self.y_test) = minist.load_data()
        # [60000,28,28,1],60000个28*28像素的图片数据，每个像素点时0-255的整数，除以255.0是将每个像素值归一化为0-1间
        # 的浮点数，并通过np.expand_dims增加一维，作为颜色通道.默认值为1。
        self.x_train = np.expand_dims(self.x_train.astype(np.float) / 255.0, axis=-1)
        print(self.x_train.shape)
        # [10000,28,28]->[10000,28,28,1]
        self.x_test = np.expand_dims(self.x_test.astype(np.float) / 255.0, axis=-1)
        # 训练用的标签值
        self.y_train = self.y_train.astype(np.int)
        # 测试用的标签值
        self.y_test = self.y_test.astype(np.int)
        self.num_train_data = self.x_train.shape[0]
        self.num_test_data = self.x_test.shape[0]

    # 随机从数据集中获取大小为batch_size手写图片数据
    def get_batch(self, batch_size):
        # shape[0]获取数据总数量，在0-总数量之间随机获取数据的索引值，相当于抽样。
        index = np.random.randint(0, self.x_train.shape[0], batch_size)
        # 通过索引值去数据集中获取训练数据集。
        return self.x_train[index, :], self.y_train[index]


# （2）定义多层感知器，继承继承keras.Model，init函数定义层，call函数中组织数据处理流程
class MLP(tf.keras.Model):
    def __init__(self):
        super(MLP, self).__init__()
        # 扁平化，将28*28的二维数组，变成1维数组，0-783.
        self.flatten = tf.keras.layers.Flatten()
        # 全连接层，将784个像素点转化为100个
        self.dence1 = tf.keras.layers.Dense(units=100, activation=tf.nn.relu)
        # 全连接层，将100个单元转化为10个点
        self.dence2 = tf.keras.layers.Dense(units=10)

    def call(self, inputs, training=None, mask=None):
        # 编写数据流的处理过程，
        x = self.flatten(inputs)  # 28*28的二维矩阵扁平化为784个1维数组
        x = self.dence1(x)  # 784个映射到100个
        x = self.dence2(x)  # 100个映射到10个，分别表示对应0,1..9数字的概率
        output = tf.nn.softmax(x)  # 输出0,1..9概率最大的值。
        return output


# （3）定义训练参数和模型对象，数据集对象
num_epochs = 5
batch_size = 500  # 一批数据的数量
learning_rate = 0.001  # 学习率
model = MLP()  # 创建模型
data_loader = MNISTLoader()  # 创建数据源对象
optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate)  # 创建优化器，用于参数学习优化
# 开始训练参数
num_batches = int(data_loader.num_train_data // batch_size * num_epochs)  # 计算训练数据的总组数
arryindex = np.arange(num_batches)
arryloss = np.zeros(num_batches)
# （4）通过梯度下降法对模型参数进行训练，优化模型
for batch_index in range(num_batches):
    X, ylabel = data_loader.get_batch(batch_size)  # 随机获取训练数据
    with tf.GradientTape() as tape:
        ypred = model(X)  # 模型计算预测值
        # 计算损失函数
        loss = tf.keras.losses.sparse_categorical_crossentropy(y_true=ylabel, y_pred=ypred)
        # 计算损失函数的均方根值，表示误差大小
        loss = tf.reduce_mean(loss)
        print("第%d次训练后:误差%f" % (batch_index, loss.numpy()))
        # 保存误差值，用于画图
        arryloss[batch_index] = loss
        # 根据误差计算梯度值
    grads = tape.gradient(loss, model.variables)
    # 将梯度值调整模型参数
    optimizer.apply_gradients(grads_and_vars=zip(grads, model.variables))

# 画出训练误差随训练次数的图片图
plot.plot(arryindex, arryloss, c='r')
plot.show()
# （5）评估模型的准确性
# 建立评估器对象
sparse_categorical_accuracy = tf.keras.metrics.SparseCategoricalAccuracy()
# 用测试数据集计算预测值
ytestpred = model.predict(data_loader.x_test)

# 向评估器输入预测值和真实值，计算准确率
sparse_categorical_accuracy.update_state(y_true=data_loader.y_test, y_pred=ytestpred)
print("test accuracy is %f" % sparse_categorical_accuracy.result())

