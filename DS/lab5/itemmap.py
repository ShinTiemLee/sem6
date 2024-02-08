#import string
import fileinput
for line in fileinput.input():
	data = line.strip().split(",")
	if len(data) == 8:
		date, time, location, item, cost, payment ,q1,q2= data
		print ("{0}\t{1}".format(location,payment))