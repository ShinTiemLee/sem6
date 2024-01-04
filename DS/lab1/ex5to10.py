x=(1,3,5,7,9,2,4,6,8,10)
print(x[:5])
print(x[5:])

x=(12, 7, 38, 56, 78 )
y=[]
for i in x:
	if i%2==0:
		y.append(i)
y=tuple(y)
print(y)

x=[11, -21, 0, 45, 66, -93]
for i in x:
	if i<0:
		print(i)

countpos,countneg=0,0
for i in x:
	if i<0:
		countneg+=1
	else:
		countpos+=1
print('pos:%d, neg:%d'%(countpos,countneg))

x.clear()
print(x)