import random
import numpy as np

A = np.array ([2,5,10])
A.dtype
B=np.array ([2.4,10.6,5.2])
B.dtype
A=np.array([(3,4,5),(12,6,1)])
S=np.arange(10,30,5)
print (S)
P=np.arange( 0, 2, 0.3 )
print(P)
S1=np.linspace(0,2,9)
print(S1)
random.seed(10)
print(random.choice([1,2,3,4,5]))
print(random.randrange(25,50,2))
print(random.random())
a = np.arange(15).reshape(3, 5)
print(a.shape)
print(a.T)
c = np.arange(24).reshape(2,3,4)
print(c)
print(c[...,2])