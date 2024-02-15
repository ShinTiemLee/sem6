import sys

c_odd=0
c_even=0
old=None
for line in sys.stdin:
	line=line.strip().split("\t")
	num,count = line
	count=int(count)
	if old and old!=num:
		if int(old)%2==0:
			c_even=count+c_even
		else:
			c_odd=count+c_odd
		old=num
	else:
		old=num
if int(old)%2==0:
	c_even=count+c_even
else:
	c_odd=count+c_odd
print("Odd: ",c_odd,"\nEven: ",c_even)
