
class A:
	
	def get_string(self):
		self.str=input("Enter string: ")

	def print_string(self):
		print(self.str.upper())
		
		


if __name__ == '__main__':

	obj=A()
	obj.get_string()
	obj.print_string()

