import numpy as np

a =np.array([[2,23,4],
             [2,23,4],
             [2,23,4]], dtype = np.int64)
print(a)
print(np.ndim(a))
print(a.dtype)

a = np.ones((2,2,2,2), dtype = np.int64)
print(a)
print(a.dtype)

a = np.arange(16).reshape(2, 2, 2, 2)
print(a)

a = np.linspace(1, 10, 4)
print(a)

a = np.array([10, 20, 30, 40])
b = np.arange(4)
print(a, b)
c = a - b
print(c)

print()
a = np.array([1, 2 ,3])
print(np.arccos(np.cos(a)))

a = np.arange(9).reshape(3, 3)
b = np.arange(9).reshape(3, 3)
a.dot(b)
print(a*b)
print(np.dot(a, b))

print("------")
a = np.arange(27 * 3).reshape(3, 3, 3, 3)
print(a)
print(np.average(a, axis = 1))