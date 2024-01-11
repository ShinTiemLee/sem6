import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
i = 1
while i < 6:
  print(i)
  i += 1
else:
  print("i is no longer less than 6")

list=[-1,-2,3,4]
i=0
while i<len(list):
  if list[i]<0:
    print(list[i])
  i+=1

student={'name':['A','B'],'height':[6,5.5],'qualification':['PG','UG']}
df=pd.DataFrame(student)
print(df)
address=['manipal','mangalore']
df['address']=address
print(df)
df.insert(1,"weight",[45,60])
print(df)