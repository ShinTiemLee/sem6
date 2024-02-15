import fileinput
for line in fileinput.input():
	data = line.strip().split("\t")
	if len(data)==2:
		d1,d2 = data
		print("{0}\t{1}".format(d1,d2))