import pandas as pd
import numpy as np
data = {'Name':['Kavitha', 'Sudha', 'Raju','Vignesh'],'Age':[28,34,29,42]}
df = pd.DataFrame(data, index=['rank1','rank2','rank3','rank4'])
print(df)

df1=pd.DataFrame({'A':pd.Timestamp('20130102'),'B':np.array([3]*4,dtype='int32'),
'C':pd.Categorical(['Male','Female','Male','Female'])})
print(df1.shape)
print(df1.dtypes)
print(df1.head())
print(df1.tail())
df1.describe()
print(df1.T)
print(df1.sort_index(axis=1, ascending=False))

print(df1.sort_values(by='B'))

print(df1[0:3])

#print(df1['20130102':'20130110'])
print('-'*10)
print(df1.iloc[0])

print(df1.iloc[0,:2])

print(df1.iloc[0,0])

print(df1['A'])

print(df1[['A','B']])

print(df1[['A','B']][:5])

print('-'*10)

df1['F']=['Male','Female','Female','Male']
print(df1)

df1.loc[:,'D']=np.array([5]*len(df))
print(df1)

Df_new= pd.concat([df1, df], axis=1)
print(Df_new)

D= pd.concat([df1, df], axis=0)
print(D)
