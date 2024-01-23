with open("txt.txt","r") as file:
	content=file.read()
f=open("ex2.txt","w")
data=content[::-1]
f.write(data)
f.close()
print("SUCCESS")