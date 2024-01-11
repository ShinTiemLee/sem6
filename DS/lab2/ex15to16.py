import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df1=pd.DataFrame({'name':["ram","diya","chandan","james","alice"]})
df2=pd.DataFrame({'maths':[88.0,90.0,77.5,87.5,86.5],'phy':[81.0,94.0,74.5,83.0,82.5],'chem':[91.5,86.5,85.5,90.0,91.0],'bio':[82.5,83.5,84.5,85.0,93.0]})

df_new=df2
df_new.insert(0,"name",df1)
print(df_new)
df_new['total']=df_new.iloc[:,1:5].sum(axis=1)
print(df_new)

name=['annie','diya','charles','james','emily']