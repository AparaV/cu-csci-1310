'''
Functions.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2016
'''

'''
Code can be divided into meaningful blocks that
perform a task and give that code block a name to identify it. 
Then, when you want to do that task, you use that block of code by
its name.

The blocks of code are called functions. They're not unlike math
functions where there is an input to the function, an operation that
is performed, and a result. For example: f(x) = x^2. This function has
one input, labeled x. The operation is to square the input x and then
return that value. In a programming function, there can be many inputs,
the operations aren't necessarily mathematical and can be several lines
of code, and there can be zero or many return values.

Terminology:
Arguments: Inputs to the function. Can also be called parameters.
Return value: The value that the function produces. 
Function body: The lines of code in the function. This code uses the
arguments to produce a return value.
Function name: The label assigned to the function that is used in the
code to define and execute the function.

We've already worked with a lot of functions built in to Python. 
For example, the Python raw_input command is a function that has one
argument, which is the text to display, and it has a return value that
is the text that the user types. 

There are many reasons to divide your code into functions:
They make the code more readable, especially with a large program.
Repeated code only has to be written one time.
They provide structure for the code.

Write a function that converts celcius to fahrenheit.

'''
def tempCToF(Celcius):
	t = 9. / 5. * Celcius + 32
	return t

'''
This block of code defines a function called tempCToF that takes one 
argument, which is the temperature in celcius, and it returns the
temperature in fahrenheit.

Noteworthy syntax here is: 
The keyword "def" is Python's way of signifying the start of a function 
definition. 

The name of the function is next. This is the name you will use to run
the function, much like the raw_input function is called raw_input.

Then, the arguments to the function are between the (). 
These is the variables that the 
function needs to operate. In this example, the tempCToF function needs
one argument, which is the celcius temperature to convert. Without that
value, the function wouldn't have anything to use in the equation, 
Celcius wouldn't have a value and you would get an error.

Next, the body of the function. This is all of the code that will execute
when we run the function. In this example, it's just one line of code
that converts C to F.

Then, the return value. This is generally the last thing in a function.
The keyword return is important, it signifies that whatever appears 
after it is the value that the function produces.
'''
'''
Once we've defined a function, we can use it. We do this by calling 
the function using the name we gave it in the definition, for example:

The function is defined above where it's called, otherwise, python won't
know about it.
'''
F = tempCToF(32)
print(F)
'''
When you call a function, the code inside of the function definition
executes. In the tempToF example, the function has a return value, 
which means that the F will contain the calculations in the function
after the function executes.

When code is structured using functions, you don't change
the functionality, you just change the structure. You will get the 
same result from your C to F calculation whether you put the equation
or not. But, as your programs start to include more and more code, 
functions become very important for keeping your ideas organized. 
'''

'''
Functions can also have no arguments or no return value. In this example,
the function will print two lines to the terminal. But, it doesn't need
any additional values to run properly, everything is provided in the 
function, and therefore, it doesn't need to have parameters. It also
doesn't produce anything, we know this because there's no return at the
end of the code.
'''
def printSomeStuff():
	print("print first line")
	print("print second line")
	
'''
This example is called the same way as the tempToF function, except that
the () are empty, and we don't see any variable equal to the function
'''
printSomeStuff()

'''
Here's another example. This function is called addTwoNumbers and it 
takes two arguments, both numbers, and it returns the sum of those 
numbers.
'''
def addTwoNumbers(num1, num2):
	return num1+num2
'''
The function has a return value, so when you call it, you want the result
of the calculations in the function. To get that result, you set a 
variable = to the function:
'''		
s = addTwoNumbers(5,4)
print(s)

'''
Exercise: write a function that has one argument that is a string. The
function should count the number of d or D in the string and return that
value. 
'''
def countDs(s):
	count = 0
	for letter in s:
		if letter == "d" or letter == "D":
			count = count + 1
	return count

sentence = "The quick brown fox jumped over the lazy dog"

d = countDs(sentence)

	
'''
A few things changed when we put the code in a function. The sentence is
now an argument that will be set outside the function. This will be
the string that the function uses for counting. The other change is that
we removed the print, and the function will now return a number.
'''
'''
Once we have the function, we can call it. We will pass it the sentence
that we've declared.
'''

print "The sentence has ", d, "ds"

'''
By having a countDs function, we've hidden the actual calculation,
or put it in a box so that we don't really have to look at it. The name
of our function tells us what it's doing.
In this example, I wrote the function to return a number, and depending
on what you wanted to do with the function once it's written, you could
return a number, or have it print the result of the calculation right
in the function. Here's an example of a problem where you would need it
to return a number.

Exercise: ask the user for two sentences, use the countDs function
to count the number of ds in each sentence, and then tell the user
which sentence has more ds.

'''
'''
Functions can also call other functions. It's convention, and in most
languages, required, to have a function called main that is the 
starting point for your program. The function main will be where execution
starts, and other functions can be called from within main. For example,
we could put calls to all of the functions we've written so far in main
and execute them from main.

To do this, we define a main, just as we did all of the other functions.
Then, the contents of main includes calls to all of the other functions.
'''

def main():
	F = tempCToF(32)
	print(F)
	
	'''
	This example uses a variable as the argument to tempCToF, and notice 
	that the C and the Celcius are different names. It's the position 
	that matters. tempCToF is expecting one argument, and whatever we 
	give it will be used as the value for Celcius in the function.
	'''
	C = 32
	F = tempCToF(C)
	print(F)

	printSomeStuff()
	
	#call the addTwoNumbers function
	n = addTwoNumbers(5,6)
	print(n)
	#the return statement is also important, remove it to see what happens

#now, we call main, it has no arguments and no return value.
main()


