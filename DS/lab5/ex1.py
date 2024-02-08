import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df=pd.read_csv('covid_19_data.csv')
d=(df['Province/State'],df['Confirmed'])
for (i,j) in d:
	print(i,j)
