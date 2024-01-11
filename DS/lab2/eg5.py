import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
B = pd.read_html('Test runs-1.html')
# Reading a TXT file format
H = pd.read_table('HR.txt')
print(H)
print(H.head())
f=H['Department'].value_counts()
print(f)
f.plot(kind='bar')
plt.show()
f.plot(kind='pie')
plt.show()
fa=pd.crosstab(H['Gender'],H['Attrition'])
fa.plot(kind='bar')
plt.show()