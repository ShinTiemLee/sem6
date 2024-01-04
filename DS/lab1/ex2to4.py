x,y=int(input('Enter x: ')), int(input('Enter y: '))
x=x+y
y=x-y
x=x-y
print('x=%d, y=%d'%(x,y))

x=int(input('Enter x: '))
if x%2==0:
	print('x is even')
else:
	print('x is odd')

x,y,z=int(input('Enter x: ')), int(input('Enter y: ')),int(input('Enter z: '))
if x<y:
	if y<z:
		print('z is largest')
	else:
		print('y is largest')
elif x<z:
	print('z is largest')
else:
	print('x is largest')