myStr = "Three score and four years ago"
print myStr

f= myStr.find("four")
print f

c = myStr.count("a")
print c

a = "four"
myStr = myStr.replace(a, "many")
print myStr


listInt = [100, 90, 100, 33]
listStr = ["hello", "there"]
listMixed = ["hello", 100, "there", 33]
listList = [listInt, listStr, listMixed]

print listInt
print listStr
print listMixed
print listList

#iterator - loop through collection
#collection could be list, string, lines in file
for i in listInt:
	print i

for i in listList:
	for j in i:
		print j

numbers = range(0,10)
print numbers

#function that prints a string
def myFunction(myStr):
	print myStr

myFunction(myStr)
myFunction(5)

#function to find index of an item in list
def findIndex(listToSearch, val):
	for i in range(0, len(listToSearch)):
		if listToSearch[i] == val:
			return i
	return -1

print findIndex(listInt, 33)
