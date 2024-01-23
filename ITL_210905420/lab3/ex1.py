x= float(input("Enter op1:"))
y= float(input("Enter op2:"))
op=input("Enter operator:")
if(op=='+'):
	print(x+y)
elif op=='-':
	print(x-y)
elif op=='/':
	print(x/y)
elif op=='*':
	print(x*y)
else:
	print("Error")