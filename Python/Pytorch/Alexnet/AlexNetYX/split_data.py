import os
from shutil import copy
import random

def mkfile(file):
    if not os.path.exists(file):
        os.makedirs(file)

# 获取data文件夹下所有文件夹名（即需要分类的类名）
file_path = "./data_name"
label_class = [cla for cla in os.listdir(file_path)]

# 创建 训练集train 文件夹，并由类名在其目录下创建子目录
mkfile('data/train')
for cla in label_class:
   mkfile('data/train/' + cla)

# 创建 验证集val 文件夹，并由类名在其目录下创建子目录
mkfile('data/val')
for cla in label_class:
    mkfile('data/val/' + cla)

# 划分比例，训练集 : 验证集 = 8 : 2
split_rate = 0.2

# 遍历所有类别的全部图像并按比例分成训练集和验证集
for cla in label_class:
    cla_path = file_path + '/' + cla + '/'
    images = os.listdir(cla_path)
    num = len(images)
    val_index = random.sample(images, k=int(num * split_rate)) #random.sample()随机截取列表
    for index, image in enumerate(images):
        if image in val_index:
            image_path = cla_path + image
            new_path = './data/val/' + cla
            copy(image_path, new_path)
        else:
            image_path = cla_path + image
            new_path = './data/train/' + cla
            copy(image_path, new_path)
        print("\r[{}] processing [{}/{}]".format(cla, index + 1, num), end="")
    print()

print("processing done!")




















