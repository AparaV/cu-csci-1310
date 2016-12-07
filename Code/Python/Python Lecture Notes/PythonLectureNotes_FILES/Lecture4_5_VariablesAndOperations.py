'''
VariablesAndOperations.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2016
'''

'''
When we work with variables in code, they have a type, such as a number
or a letter. There are a few types that you will see frequently in 
programming:

integer: whole numbers, such as 1, 2, 45, 12
float: decimal numbers, such as 4.3, 1.2 (These are also called a "double"
in some languages)
bool: value is either true or false, which is stored as 0 or 1
string: literal letters and numbers, such as "this is csci1300"
list: a collection of other types, such as [1, 3, "test", "5"]

'''

'''
The print statement is a command built in to Python. When you run the 
.py file, the Python interpreter knows to display whatever is contained
between the (). 
'''

print "Hello world"

#Can print other strings by changing the words in the print statement
print "Welcome to CSCI1300"
print "Here is yet another message"

'''
When you create a variable, a location is setup in memory with the variable
name as an identifier for that location and the value at that location.
For example, you can create a variable called "a" with a value of 5 using

'''
a = 5

'''
I've made "a" an integer just by giving it an integer value. 

After that command executes, there is a location in memory that is identified
as "a" and that location holds a value of 5. We don't need to know where
in memory the value is stored, we just refer to "a". In this case, the 
identifier "a" is recognized until the program quits. 

You can access "a" and print it's value by doing
'''
print a

'''
We can do this again, creating another variable called b and give it 
a value of 6, and then print out the value of b.
'''
b = 6
print b

'''
The a and b we've created both hold whole numbers,
called integers, so we say that a and b are integers, that's their type.
'''

'''
Another variable type is called a string. Strings contain one or more 
characters, either letters, numbers, spaces, or other symbols, and the 
value of the variable is the entire string. For example, we can create
a variable called "aStr" that holds the value "this is a string".
'''
aStr = "this is a string"
#To check the value of aStr, do
print aStr

'''
There are also numbers with decimal values. These are called floats in 
Python, which is short for floating point. An example of a float is
'''
c = 4.5
#To check the value of c, use the print statement
print c

'''
The value of a string doesn't necessary need to be a letter. We can also 
have strings that are numbers. For example, a string called x with the value
"2.2" and a string called y with the value "4.4".
'''
x = "2.2"
y = "4.4"
print x
print y

'''
Another Python variable is called a boolean, which can only have two 
values, True or False. These True of False values reduce down to a 1 or
0, on or off. For example, to create a boolean variable called myBool that
is set to True, you do
'''
myBool = True
print myBool

'''Notice the color coding of the keyword True. It's blue, indicating that
Python recognizes it. If you change the capitalization so that True is 
true, the highlighting goes away and you'll get an error when you run 
the code. Python is case-sensitive, True is different than true.
'''
myBool = False

'''Python also has a variable type called a list, which can store multiple
elements together as one variable, and each of those elements can 
actually have a different type.

For example, here we have a variable called myList where the first item
is an integer, second item is a float, and third item is a string.
'''
myList = [4, 6.5, 'a']
print myList
'''
myList has three items in and to access each individual item, we use
the index of the item. Indexing starts at 0, so the first item is 
myList[0], the second is myList[1], and the third is myList[2]
'''
print myList[0]
print myList[1]
print myList[2]

'''Later in the semester, we'll talk about two other data types, one 
is a dictionary and the other is a set
'''
'''
The type of the variable matters here because of how the variable is handled
when you do operations with it. If you add two numbers together, you get
the sum of those numbers, but if you add two strings together, you get
a new string that is both strings appended together.

For example, let's create float variables and two string variables with
numbers and look at what happens when they are added. This is an operation
on two variables
'''
a = 5.1
b = 4.5
c = a + b
print c

a = "5.1"
b = "4.5"
c = a + b
print c

'''
The + operator can also be used on strings that do not have numbers.
For example, adding two strings creates a new string
'''
my_str = "hello world "
my_str2 = "how are you today"
new_str=my_str + my_str2
print new_str


'''
There are also standard operations on numbers that you are familiar with.
An example of dividing two numbers:
'''
a = 5.2
b = 6.2
c = b / a
#c is a floating point number, it has a decimal component
print c

a = 5
b = 6
c = b / a
#c is 1 because an int div by an int produces an int
print c

#multiplication
z = a*b
print z
#exponentiation, notice the double *
#x2^2
z = a**2
print z
#x2^y2
z = a**b
print z
#you can even combine operators in one equation
z2 = a + (b * z) / a
print z2

'''
Exercise: given a circle with a radius of 10 units. Calculate the 
area and circumference of the circle. 

The formula for area is a = pi*r^2
The formula for circumference is 2*pi*r
ANSWER:
'''
radius = 10
#for a variable name, I'm using something meaningful, area and circ
area = 3.14 * radius**2
circ = 2 * 3.14 * radius
print "the area is:",area 
print "the circumference is:",circ

'''
We've looked at operations, primarily on numbers and 
strings. The + operator could work on both numbers and strings, however,
some of the other operators you've seen, such as *, /, and - are possible
only on numbers. If you try to divide a string by another string, or even
by a number, what does that mean. It doesn't really make sense to do so,
which is why you'll get an error. For example, c = s / a in the following
equations won't work.
'''
a = 5
s = "this is a string"
#c = s / a

'''
Another operator for numbers that we haven't discussed yet, but it very
useful in programming is the modulus operator. The modulus will produce
the remainder of a division. To understand this, it's helpful to think
back to when you learned long-division in 5th grade. This was before
you were introduced to decimals, most likely. In 5th grade division,
if you divide 75/50, you get 1 R 25, also known as 1 remainder 25. This
is because 50 goes into 75 one time with 25 left over. Since 25 is less
than 50, there isn't another chunk of 50 in the 75. We can see this in 
code in the following example
'''
a = 75
b = 50
c = int(a/b)
print(c)
c = a%b #the % is the mod operator
print "mod ",c

'''
The mod operator is really useful for finding out how many discrete 
elements are left over after a division. For example, consider the 
following exercise: 

Convert 200 seconds to minutes and seconds

If you just do division only, you'll have a fractional number of minutes,
but you won't have minutes and seconds. To get seconds, you need to use
the mod operator.

'''
'''
Class exercise: Convert 200 seconds to minutes and seconds

The answer is in Lecture5Mins.py, but don't look at it until you've 
worked through the problem
'''

'''
In the examples with + so far, both variables have been of the same type.
If you try to add two variables with types where the + operator has 
different meaning, you will get an error. For example, adding an integer
and a string will result in Python being confused, is the + meant to be
the addition of two numbers, or the appending of two strings 

For example, we can create two new variables with different types and add
them, and then watch the error when we print the result.
'''
n = 5
s = "the number is "
#uncomment the next line to see the error
#sn = s + n
#print(sn)
'''
The previous print statement produced a type error. Python sees the s first
and then the + and parses the command as appending two strings, and expects
that the variable to the right of the + will be a string. When the n
is reached and it's not a string, an error is generated. 
'''

'''
To solve this problem, you can cast one of the variables to match the type
of the other variable. The variable that you choose depends of what 
you're trying to achieve and the values of the variables. The options here
are to cast s as a float or integer, or cast n as a string. Since s 
isn't a numeric value, we can't cast it as such. However, we can cast
n as a string, and then 5 becomes "5".
'''
sn = s + str(n)
print sn

'''
If you have a string and you want to be a number, you
would cast it as a float, like so
'''
x = float(x)
print x
'''
The float command is built in to Python and to use it, anything between
the parentheses is called an argument to the float function. float will
produce a new value that is a type float, using the argument.

Notice here that both the argument to the float function and the return
value of the float function are both called x. It's the same x. You may be
wondering how you can have two things, one on each side of an = sign
that are not actually equal. The left-hand side does not equal the right
hand side. Recall what x is, it's a memory location. What's happening here
is we're saying take the value at the x location, convert it to a float,
and return it back to the x location. You'll see this over and over again
in programming, where variables in programming and the = sign in programming
is not the same as the = sign from math class.
'''

'''
There is also a conversion from float to integer. Here we use the Python 
keyword int to convert the existing value of x to an integer x. Depending 
on the value in x, we may actually change its value. Since integers don't 
have decimal values, if x has a decimal, it will be truncated, and you
will be left with the whole number portion only.
'''
x = int(x)
print x

'''
There are a few ways to get user input in Python. There is a built-in 
function called raw_input that will prompt the user when the program runs.

The Python input command will display a prompt on screen, and wait for 
a response typed on the keyboard by the user. Whatever the user types
in then stored in a variable, that can then be used in the code. 

For example,
'''
d = raw_input("Please enter a number:")
print d
print type(d)
'''
the raw_input command waits for the user to enter something when the 
program runs in this example, the value they enter is stored in 
variable d, which is a string by default doing any math operations on 
d requires converting it to a number, such as an int or float
'''
#for example, this expression will break
#e = d + 5

#however, this is legal
e = int(d) + 5
print d," plus 5 equals ",e

'''
Another option is to use a built-in feature of python that evaluates the
input and assigns it a type based on its value. That command is called
eval.
'''
d = eval(raw_input("Please enter a number:"))
print d
print type(d)

#for example, we could modify the Lecture5Mins.py code to work for any number of seconds
#Python has an input command to get user input
seconds = raw_input("Enter a number of seconds to convert: ")
#next, convert seconds to an integer, it's treated as a string by default
seconds = int(seconds)
#next, do the calculations
mins = int(seconds / 60)
#to get how many seconds, you want the modulus of dividing by 60
#this is the fractional seconds in a minute
s = seconds % 60
print "200 seconds is ",mins, " mins and ", s, "seconds"

'''
Class exercise:
Burning one gallon of gasoline in your car produces 19.4 pounds of CO2.
First, Write a program to answer the following question: 
If the Subaru Outback gets 26 mpg, how much CO2 does this vehicle 
produce if it travels 12,000 miles a year? Print the result in a nice
print statement.

Next, modify the code to ask the user how many miles per year they travel and
the mpg that their car gets, use these inputs in your calculation instead
of the 12,000 miles and the 26mpg

The answer is in Lecture5Subaru.py, but work through the problem first 
before looking at the solution.

The value of having miles and mpg be inputs to the calculation for 
CO2PerYear is we can calculate this value for any yearly mileage and 
any mpg rating.

'''
