import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df=pd.read_csv('covid_19_data.csv')

for ind in df.index:
	print(df['Country/Region'][ind],"\t", df['Confirmed'][ind])

	
	
