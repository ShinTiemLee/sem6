import fileinput
transactions_count = 0
sales_total = 0
for line in fileinput.input():
	data = line.strip().split("\t")
	if len(data) != 2:
	# Something has gone wrong. Skip this line.
		continue
	current_key, current_value = data
	transactions_count += 1
	if(current_value=="Confirmed"):
		continue
	sales_total =sales_total+ int(current_value)
print (transactions_count, "\t", sales_total)