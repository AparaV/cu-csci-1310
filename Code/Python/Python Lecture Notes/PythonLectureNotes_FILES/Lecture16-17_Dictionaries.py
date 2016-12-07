'''
Lecture16.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Spring, 2014
'''

'''
So far in this class, we have discussed numbers and strings and lists.
Numbers are integers and floats, and strings and lists are both data
types that are collections. Today we are discussing another type of 
data structure called a dictionary.

Dictionaries are similar to lists in that they are used to store a 
collection of data, and there is an index to access individual items
in the collection. However, dictionaries are unique in that they have
a key as the index, and that key is not a number, and generally has
some meaning. 

Dictionaries are used to store what are called key, value pairs.
The dictionary is a collection of data that maps keys to values
For example, lets say we want to create a dictionary where the key is 
a student's name and the value is their hometown

First, define a function, and inside that function, create a dictionary
'''
def dictionaryExample():
	'''In this example, there are two students, and the keys are the
	students' names, Matt and Jessica, and the values are Denver and 
	Boulder
	'''
	students = {'Matt': 'Denver', 'Jessica': 'Boulder'}
	'''
	The syntax here is students is the name of the dictionary. The {}
	are the dictionary syntax, then, it's key1:value1, key2:value2, etc 
	'''
	#To access the data for Matt, we index the dictionary using his key
	print(students['Matt'])

	'''
	Compare the dictionary to a list, and how we access items in a list.
	There isn't a key, but an index
	'''
	myList = ['a', 'b', 'c', 2]
	print(myList[2])

	'''
	We can also loop over the students collection using a for loop, 
	just like we loop over strings, lists, files
	the x here is the key in the dictionary
	'''
	for x in students:
		#we can print the x to see that it's the key
		print("the key is",x)
		print("the value is", students[x])


	'''
	As another example, the values could be numbers, such as test scores
	'''
	
	scores = {'Matt': 60, 'Jessica': 90}
	for x in scores:
		print("the key is", x)
		print("the value is", scores[x])

	#the key could be a number, such as day number of the week
	days = {1: 'Sunday', 2: 'Monday', 3: 'Tuesday'}
	for x in days:
		print("the key is", x)
		print("the name is ", days[x])

	#You can also add key/value pairs to existing dictionaries, such as
	#this creates a new entry in the scores dictionary with the key 'Rhonda' and the value of 70
	scores['Rhonda'] = 70
	print(scores)
	'''
	The value in a dictionary could also be a list. For example, say we
	had a dictionary of student names, and the value for each student
	is their class schedule.
	'''
	schedule = {'Matt':['compsci 1','humanities 1', 'science 3'], 'Jessica':
		 ['writing 1', 'science 3']}
	print(schedule)
	print("Matt's schedule", schedule['Matt'])
	'''
	Having the list as the value associated with the key means that we
	have another collection within our collection, and that collection
	also has an index. We could, for example, look at the first, second,
	and third items in Matt's class schedule
	'''
	print("Matt's classes:")
	print(schedule['Matt'][0])
	print(schedule['Matt'][1])
	print(schedule['Matt'][2])
	
	'''
	And, since the list is indexed, and we may want to grab individual
	items in the list, one at a time, in order, we can also use a for 
	loop on the list the same way we would for any other list
	'''
	classes = schedule['Matt']
	for cl in classes:
		print(cl)
	'''
	And, if you want to get really clever, you could have one loop for 
	the keys in the dictionary and another loop for the items in the list
	'''
	for key in schedule:
		classes = schedule[key]
		for cl in classes:
			print(key, cl)

dictionaryExample()
	
#write function to search dictionary and return a value if the item exists 
#function takes two parameters: dictionary and key to search for
#if item found, return it's value. Otherwise, return "item not found"
#call the function searchDictionary
#Answer is in Lecture16SearchDictionary.py

