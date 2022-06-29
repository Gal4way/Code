import numpy as np
A = np.arange(2,14).reshape((3,4))
print(np.mean(A))
print(np.max(A))
print(np.average(A))
print(np.median(A))
print(A)
print(np.cumsum(A))
print(np.diff(A))  #累差
print(np.nonzero(A))   #非0数
A = np.arange(14,2,-1).reshape((3,4))
print(A)
print(np.sort(A))    #逐行排序
print(np.transpose(A)) #转置
print((A.T).dot(A))
print(np.clip(A,5,9)) #5，9之间保留，之外删除

#索引
import numpy as np
A = np.arange(3,15).reshape((3,4))
print(A)
print(A[2])
print(A[1][1])
print(A[2,:])   #切片
print(A[:,1])
print(A[:,:])
print(A[:][:])
print(A[0][1:4])

for row in A:
    print(row)

for col in A.T:
    print(col)

for item in A.flat:   #A.flat是一个迭代器  A.flatten() 返回一个列表 作用是把A拉成一维的数据
    print(item)

print("----------------------")

#合并
A = np.array([1,1,1])[:,np.newaxis]      #使行向量变成列向量
B = np.array([1,1,1])[:,np.newaxis]

C = np.vstack((A,B))   #vertical stack
D = np.hstack((A,B))   #horizontal stack
print(A,B,"----\n",C,D)
print(D.shape)

print(A.T)    #转置后还是向量，不能用transpose将一个向量变成一个矩阵（不能改变维数）

print(A[:,np.newaxis])     #在后面加一个维度

A = np.array([1,1,1])[:,np.newaxis]
B = np.array([1,1,1])[:,np.newaxis]
C = np.concatenate((A,B,B,A),axis=0)
D = np.concatenate((A,B,B,A),axis=1)

print("-----------")
print("分割")
A = np.arange(16).reshape((4,4))
print(A)

#指定维数
print(np.split(A,2,axis=1))    #只能进行等量的分割
print(np.split(A,4,axis=0))

#不等量的分割
print(np.array_split(A,3,axis=1)) #

print(np.vsplit(A,2))
print(np.hsplit(A,4))

A = np.array([[[1,1],[1,1]],[[1,1],[1,1]]])
B = np.array([[[1,1],[1,1]],[[1,1],[1,1]]])
print("111")
print(np.vsplit(A,2))
print(np.hsplit(A,2))

#复制
a = np.arange(4)
b = a
c = a
d = b
a[0] = 11
print(b is a)