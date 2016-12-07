'''
Lecture16_DictionaryFileIO.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2015
'''
'''
Programs often need data as part of the functionality of the program.
For example, in our lecture on strings, we typed a long string in
Geany to declare a string variable. For example, DNA = "ATGATCGGGCAGT".
When doing that, it's very easy to make a mistake, and it's also tedious
to have to type that, especially if you're working with multiple DNA
sequences, or multiple instances of any kind of data for that matter.
Another approach is to store the DNA sequence in a file and then read the
data into your program by accessing that file in your program, opening
it, reading in the data and storing it in variables, and then closing 
the file. This is really useful when you have lots of data that 
you're working with, or when you need to do something more than once. 
You can do that using what's called File I/O, these are commands in 
Python that allow you to read in data from files and also write data 
out to files for storage.

'''
'''
Lets say we have a file called textToEnglish.txt that has a bunch of 
texting slang and the english equivalents in it. There are 4000+ rows in
the file. You certainly would not want to type all of this data or ask
the user to enter it. But, since it's in a file, we can just read it in
and then work with it in our program.
The textToEnglish.txt file is on Moodle
I'm going to open it and print its contents.

Create a function to open and read the file.
'''
def openAndReadFile(filename):
	myFile = open(filename, "r")

	print myFile

	fileData = myFile.readlines()
	#close the file
	myFile.close()
	return fileData

def dataCleanup(word):
	word = word.strip("\n")
	word = word.split("\t")
	return word
	
def writeDataToFile(filename, data):
	myFileOut = open(filename, "w")
	for element in data:
		myFileOut.write(element + "\t" + data[element] + "\n")
	
	myFileOut.close()

		
def main():
	filename = "textToEnglish.txt"
	'''
	fileData contains the data read out of the file in the openAndReadFile
	function.
	'''
	fileData = openAndReadFile(filename)
	print fileData
	'''
	readlines generates a list, where each item in the list is one of the 
	lines in the file. You can access individual lines using the index of 
	the line in the file. For example, to access the first line
	'''
	print(fileData[0])
	'''and the second line'''
	print(fileData[1])

	#empty dictionary
	dictionary = {}
	for data in fileData:
		'''
		dataCleanup is a function that removes formatting and converts
		the string into a list. I put it in its own function to make this
		loop easier to read.
		'''
		word = dataCleanup(data)
		dictionary[word[0]] = word[1]

	print dictionary
	'''
	Adding rows to the file.
	What if there are abbreviations not in the file and you want to add
	them. If you do, then next time you open and read the file, your
	additions will be there.
	'''
	filename = "fileTestOut.txt"
	writeDataToFile(filename, dictionary)

	'''
	exercise: add a new abbrev and translation to your dictionary and write
	it out to a file. You can use the same filename, or create a new one
	'''
	
main()





