import random
import numpy as np

a = np.array( [20,30,40,50] )
b = np.arange( 4 )
print(b)
c = a - b
print(c)
print(b**2)
print(10*np.sin(a))
print(a<35)
A = np.array( [[1,1],[0,1]] )
B = np.array( [[2,0],[3,4]] )
print(A*B)
print(A.dot(B))
b = np.arange(12).reshape(3,4)
print("col sum {}".format(b.sum(axis=0)))
print("row sum {}".format(b.sum(axis=1)))
a = np.arange(10)**3
print(a[0:6:2])
b=np.array([[ 0, 1, 2, 3],
[10, 11, 12, 13],
[20, 21, 22, 23],
[30, 31, 32, 33],
[40, 41, 42, 43]])
b.ravel()
print(b)
A1=np.array([(3,4,5),(12,6,1)])
A2=np.array([(1,2,6),(-4,3,8)])
D1=np.vstack((A1,A2))
D2=np.hstack((A1,A2))
print(D1)
print(D2)
a=np.array([(3,2,9),(1,6,7)])
s=0
for i in range(a.shape[0]):
	for j in range(a.shape[1]):
		s+=a[i,j]
print(s)