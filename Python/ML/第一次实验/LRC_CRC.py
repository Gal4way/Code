import scipy.io as sio
import numpy as np
from tqdm import tqdm
import matplotlib.pyplot as plt

mat = sio.loadmat('ORL_32_32.mat')
img = mat['alls']
labels = mat['gnd']
label = np.unique(labels)

count = 0
acc_sum = 0
k = 2
b = [0]
for i in range(-5, 10, 2):
    b.append(pow(10, i))
L1_acc = []
L2_acc = []
Linf_acc = []
Res_acc = []

print('starting...')
for i in range(k):
    print(i, '-fold:')
    test_ind = []
    for j in range(len(label)):
        test_ind.append(range(j * 10 + i * 5, j * 10 + (i + 1) * 5))
    test_ind = np.array(test_ind).reshape(len(label) * 5)

    test_img = img[:, test_ind]
    test_label = labels[0, test_ind]
    teMat = np.mat(test_img / 1.0)

    train_ind = test_ind + (5 - 10 * i)
    train_img = img[:, train_ind]
    train_label = labels[0, train_ind]
    trMat = np.mat(train_img / 1.0)
    coeff = []
    for j in b:
        regress_w = (trMat.T * trMat + j * np.identity(len(train_ind))).I * trMat.T * teMat
        coeff.append(regress_w)

    print('computing predict results')
    for j in tqdm(range(len(coeff))):
        L1_score = []
        L2_score = []
        Linf_score = []
        res_score = []
        for m in label:
            temp_ind = [l for l,x in enumerate(train_label) if x == m]
            Mat = (coeff[j])[temp_ind, :]
            XMat = trMat[:, temp_ind]
            tePre = XMat * Mat
            Re_dist = teMat - tePre
            res_score.append(sum(np.power(Re_dist, 2)))

            j1scores = sum(map(abs, Mat))
            L1_score.append(j1scores)

            j2scores = sum(np.power(Mat, 2))
            L2_score.append(j2scores)

            jinfscores = np.max(np.abs(Mat), axis = 0)
            Linf_score.append(jinfscores)

        res_score = np.array(res_score).reshape(40, 200)
        L1_score = np.array(L1_score).reshape(40, 200)
        L2_score = np.array(L2_score).reshape(40, 200)
        Linf_score = np.array(Linf_score).reshape(40, 200)

        index = []
        for i in range(200):
            index.append(np.argmax(L1_score[:, i]))
        predicts = label[index]
        difs = predicts - test_label
        L1_acc.append(np.sum(difs == 0) / 200)

        index = []
        for i in range(200):
            index.append(np.argmax(L2_score[:, i]))
        predicts = label[index]
        difs = predicts - test_label
        L2_acc.append(np.sum(difs == 0) / 200)

        index = []
        for i in range(200):
            index.append(np.argmax(Linf_score[:, i]))
        predicts = label[index]
        difs = predicts - test_label
        Linf_acc.append(np.sum(difs == 0) / 200)

        index = []
        for i in range(200):
            index.append(np.argmin(res_score[:, i]))
        predicts = label[index]
        difs = predicts - test_label
        Res_acc.append(np.sum(difs == 0) / 200)

results = [L1_acc, L2_acc, Linf_acc, Res_acc]
np.savetxt("results.txt", results, fmt = "%6.4f")

results = np.array([L1_acc, L2_acc, Linf_acc, Res_acc]).reshape(4, k, 9)

print("ploting")
labels = ["L1", "L2", "Linf", "Res"]
mark = ["s", "o", "^", "x"]
b = range(-7, 10, 2)
k = 0
for i in range(4):
    plt.plot(b, results[i, k, :], marker = mark[i], label = labels[i])
plt.xticks(b)
plt.ylim(0, 1)
plt.legend()
plt.savefig("results.png")



































