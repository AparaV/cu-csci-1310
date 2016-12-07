import math

def printHelloWorld():
	print "Hello World"

#function that checks whether any value in list is greater than some other number
def greaterThan(arr, val):
	for x in arr:
		if x > val:
			return True
	return False

def subString(string, index):
	return string[index:len(string)]

def findSubString(a, b, string):
	for x in range(0,len(string)):
		if string[x] == a:
			i = x
		if string[x] == b:
			j = x
			break
	return string[i:j+1]

if __name__ == "__main__":
	print "Hello World"
	printHelloWorld()
	
	numList = [1, 2, 3, 4, 5]
	num = -33
	print greaterThan(numList, num)
	
	print subString("Hello", 2)
	
	string = "Hello World"
	print findSubString("H", "o", string)
	
