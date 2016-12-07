'''
Lecture16SearchDictionary.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Spring, 2014
'''

'''
Example showing how to search a dictionary. In this example, you will
need to loop through each item in the dictionary and check if that item
is in the dictionary by checking the dictionary keys. Your loop over the
dictionary items is the same syntax as looping through other types of 
collections, such as strings, lists, and lines in a file. Checking that
the key is in the dictionary is similar to checking that an item is in
a list or that a string contains a certain letter.
'''
def searchDictionary(dictionary, searchKey):
	#initialize val
	val = "item not found" #not found, we're assuming none of the values in dictionary are not found
	#item is the key in the dictionary
	if searchKey in dictionary:
		val = dictionary[searchKey]
	
	'''
	Another approach is to loop through the dictionary and check if the
	key is to search key.
	'''	
	'''
	for item in dictionary:
		if item == searchKey:
			val = dictionary[item]
	'''
	return val
	
def main():
	students = {'Matt': 'Denver', 'Jessica': 'Boulder'}
	v = searchDictionary(students, "Jessica")
	print("The value is",v)
	
	#call again for a key that doesn't exist
	v = searchDictionary(students, "Rhonda")
	print("The value is",v)
	
	
main()
