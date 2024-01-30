
class subset:
	def __init__(self,set,key):
		self._set=set
		self._key=key

	def find_subset(self):
		tset=list()
		size=len(self._set)
		for i in range (size-1):
			for j in range(i+1,size):
				if int(self._set[i])+int(self._set[j])==self._key:
					print(self._set[i],' ', self._set[j])
					exit()
		print("No such pair exists")
		
		


if __name__ == '__main__':

	set=list((input("Enter integers: ").split(' ')))
	key=int(input("Enter the required sum:"))
	findallsubset=subset(set,key)
	findallsubset.find_subset()

