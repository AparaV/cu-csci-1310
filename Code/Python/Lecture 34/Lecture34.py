#FILE IO
import array

def openFileAndRead(filename):
	myFile = open(filename, "r")
	print myFile
	fileData = myFile.readlines()
	print type(fileData)
	print fileData

if __name__ == "__main__":
	
	filename = "textFile"
	#openFileAndRead(filename)
	
	#Dictionaries
	#order is wibbly wobbly for dictionaries
	foo = {'Hello' : 1, 'World' : 3, "Something": 3, "Hello": 2}#value gets overwritten
	
	for i in foo:
		print "key is ", i
		print "value is ", foo[i]
	
	foo["Die"] = "don't"
	
	for i in foo.keys():
		print "key is ", i
		print "value is ", foo[i]
		
	numbers = {"odd" : [1, 3, 5], "even" : [2, 4, 6]}
	
	numbers["odd"].append(7)
	
	for i in numbers:
		print "key is ", i
		print "value is ", numbers[i]
		
	#read json file
	import json
	f = open("forecastData")
	data = json.load(f)
	print data
	
	for key in data.keys():
		print key, data[key]
		
	#get just the date value
	print "date"
	print data['date']
