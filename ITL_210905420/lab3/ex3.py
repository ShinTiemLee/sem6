def bsearch(l,r,key,arr):
	mid=int(l+(r-l)/2)
	if l>r:
		print("Not found")
		exit()
	if key==arr[mid]:
		print("Key found")
		exit()
	elif key<arr[mid]:
		bsearch(l,mid-1,key,arr)
	else:
		bsearch(mid+1,r,key,arr)

arr=list(input("Enter elements"))
key=input("Enter key to be found")
bsearch(0,len(arr)-1,key,arr)