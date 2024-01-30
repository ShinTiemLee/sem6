
class power:
	@classmethod
	def pow(self,x,n):
		res=x
		for i in range (n-1):
			res=res*x
		return res
		
		


if __name__ == '__main__':

	x=int((input("Enter x: ")))
	n=int(input("Enter n:"))

	print(power.pow(x,n))

