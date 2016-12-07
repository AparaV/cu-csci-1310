'''
Lists
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2016
'''
'''
Lists are a data type similar to strings in that they store a collection
of data in a sequence. Unlike strings, lists store sequences of any data
type. For example, you can have a list of integers, a list of strings, a
list of other lists, or a list that contains a mix of data types.

There is functionality built-in to python to handle the operations that
programmers often want to do to lists, such as inserting, deleting, and
finding elements.
'''
#some examples of lists
listInt = [100, 90, 95, 80, 100]
listStr = ["programming", "chemistry", "math"]
listMixed = ["programming", "chemistry", 1, 2, 3]
listLists = [listInt, listStr, listMixed]
print listInt
print listStr
print listMixed
print listLists
'''
The first list is a list of integers, the second is a list of strings,
the third list is a mix of strings and integers, and the last one is
a list of lists. We could also add non-list elements to the list of 
lists without any issues.
'''
'''
Each element in a list can be accessed by its index in the list. The 
indexing starts at 0 to access the first list element. The index 1 
is used to access the second element in the list
'''
#print the first element
print listInt[0]
print listStr[0]
print listLists[0]

#print the second element
print listInt[1]
print listStr[1]
print listLists[1]

'''
Regardless of the type of the first element, the [0] can access it and
[1] can access the second element.
'''
'''You can also access a group of elements in the list'''
print listInt[:2]
print listStr[1:3]
'''
Appending elements to the end of a list is handled with the append 
command.
'''
'''
There are a few ways to change the contents of a list. You can overwrite
existing elements, insert new elements, add new elements to the end of 
the list, and delete elements from the list.
'''
#to update an element, access the element with its index
#update the third element of listInt to be 2000
listInt[2] = 2000

'''
To append an element to the end of the list, use the append method that
is built-in to the python functionality for lists.

'''
#add a 4 at the end of the listInt list
listInt.append(4)
#add "another class" to the end of the listStr list
listStr.append("another class")
#add a 2 to the end of the listLists list
listLists.append(2)
print listInt

'''
Elements can also be inserted into a list at a specified position.
The insert method has two parameters. The first parameter is the index
where the new element should be added, and the second parameter is the 
value to insert in the list.

When an element is inserted, the other elements in the list will all be
shifted by one position to make room for the new element. 

For example, to insert the value 1000 at index 1 in listInt, use:
'''
listInt.insert(1, 1000)
print listInt
'''
After the insert, the list element that was at listInt[1] is now 
listInt[2] and the list element that was listInt[2] is now listInt[3],
and so on.
'''
'''
To remove an element from a list, there are two different approaches.
You can access the element by its index, or by its value.

To delete by its index, use the del keyword
'''
del listInt[1]
print listInt
'''
To remove an element by its value, use the list remove method. The 
parameter to the method is the element to remove.

There is a danger with this approach that it will generate an error
if the element is not found in the list.
'''
listInt.remove(2000)
print listInt
'''
calling listInt.remove(1000) would generate an error because 1000 has
already been removed.
'''
'''
Unlike strings, where you can use a built-in find method to locate an
element in a string, with lists you have to search by looping through
each element until you find what you're looking for. You can check the
values in the list by comparing the list element to the search value.

There are different approaches for searching a list, and the appropriate
approach depends on what you need.
'''
#example: determine the index of 80 in listInt
for x in range(0, len(listInt)):
	if listInt[x] == 80:
		break
print listInt[x]
'''
In this example, we search until 80 is found and then break out of the
loop. The value for x will be the index where 80 is found because we
don't update it after the conditional. We break out of the loop before
evaluating the for loop condition again.
'''
'''
Here is another approach that could produce a different answer. Instead
of breaking out of the loop, we continue looping until the end of the 
list.
'''
index = 0
for x in range(0, len(listInt)):
	if listInt[x] == 80:
		index = x
print listInt[index]
'''
Using this approach, we actually find the last instance of a value in
the array. Do an example where there are multiple 80s in the array and
check the value of index after the loop exits.

Exercise: could you find the indices where all instances of a search 
value are located in a list?
'''
'''
Here's even one more way to find something in a list.
'''
for x in listInt:
	if x == 80:
		print x, "found"
		break

#and then remove it, just because		
listInt.remove(x)
print listInt
