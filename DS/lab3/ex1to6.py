import numpy as np
import random

num=int(input("Enter num to find its factors: "))
for i in range(1,num+1):
	if num%i==0:
		print(i)

a=np.arange(10).reshape(2,5)
print("col sum:",a.sum(axis=0))
print("row sum:",a.sum(axis=1))
A1=np.array([.1,.2,.3])
print(A1)
A2=np.array((1,2,3,4,5,6))
print(A2)
A3=np.zeros((3,4))
print(A3)
A4=np.arange(0,20,5)
print(A4)
print(A3.reshape(2,2,3))
A=np.arange(12).reshape(3,4)
B=np.arange(12).reshape(3,4)
print(A)
print("max of array is {}".format(A.max()))
print("mim of array is {}".format(A.min()))
print("sum of array is {}".format(A.sum()))
max=0
min=0
for i in range(A.shape[0]):
	print("max of row {} is {}".format(i,A[i,:].max()))
	print("min of row {} is {}".format(i,A[i,:].min()))
for i in range(A.shape[0]):
	print("max of col {} is {}".format(i,A[:,i].max()))
	print("min of col {} is {}".format(i,A[:,i].min()))
print(A.T)
print(A+B)
print(A*B)