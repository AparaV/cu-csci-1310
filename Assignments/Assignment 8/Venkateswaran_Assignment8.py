'''
Assignment 8
Aparajithan Venkateswaran
TA: Camilla Lambrocco
REC: 101
'''

'''Tokenize Data - Split string by ',' delimiter'''
def tokenizeData(data):
	word = data.strip("\r")
	word = word.split(",")
	return word

'''File IO'''
def CreateDictionary(filename):
	
	#error check
	try:
		myFile = open(filename, "r")
		fileData = myFile.readlines()
	except IOError:
		print "File could not be opened"
		return "NA"
	
	#the whole file is encoded as a single string with "\r"
	#so I am splitting it with that escape character
	fileData = fileData[0].split('\r')
	
	dictionary = {}
	
	for data in fileData:
		word = tokenizeData(data)
		dictionary[word[0]] = word[1]
	
	return dictionary

'''Search Function'''
def searchDictionary(dictionary, x):
	for key in dictionary:
		if key == x:
			return dictionary[key]
	return "Not Found"

'''Main Function'''
def main():
	filename = "textToEnglish.csv"
	
	wordDictionary = CreateDictionary(filename)
	
	#Error Check
	if wordDictionary == "NA":
		print "Program shutting down"
		return
	
	searching = True
	
	while searching:
		x = raw_input("\nEnter an abbreviation to search for. Type 'quit' to quit:\n")
		x = str(x)
		if x == 'quit':
			searching = False
			break
		else:
			xList = x.split(" ")#make a list out of the input
			string = ""
			#append the translation for each item in list
			for item in xList:
				string += searchDictionary(wordDictionary, item) + " "
			print string
		

'''Begin Main'''	
if __name__ == "__main__":
	main()
	
	


