import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

W = pd.read_excel('GermanCredit_for_Week2.xls')
print(W)

D= np.loadtxt('xyz.txt',delimiter=",")
print(D)
print(D[:5,:])