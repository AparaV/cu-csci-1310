'''
ControlStructures.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall 2016


If you need a branch in code to handle each one of multiple conditions,
you can add additional conditions. 
In Python, the syntax for this is if, elif, else.

Check if a value is greater than a given value.
'''
a = 0
if a > 0:
	print("a is greater than 0")
elif a < 0:
	 print("a is less than 0")
else:
	print("a = 0")
'''
First, evaluate the if expression. If it's true, run that code that's 
indented. If it's false, move on to the next conditional, which is the
line starting with elif. This is also checking the value of a and 
determining the truth value of the expression. This is different than 
what we've seen so far because unlike the else, the truth value is
evaluated here and the code in the indented block under the elif only
executes if the elif is true. 

If neither the if or the elif is true, run the else code block. Nothing
is evaluated for the else, that code will always execute if none of the
other conditional branches are true.
'''

#Exercise
'''
Change the Subaru code again to include the following
check the mpg that the user enters
If it's greater than 30, print a message that says "Great Job"
If it's 30 or less but greater than 15, print a message that says "Not bad".
otherwise, print a message that says, "Bad, very, very Bad"

The answer is in Lecture9SubaruIf2.py, but don't look at it until you've
worked through the problem.
'''
'''
Today, we will look at this same type of evaluation, but with strings
and checking the value of a string to determine which branch to execute.
Next, we will examine using multiple conditions in an if statement.

Think back to those books you may have read, or command-line video games
you've played where you could Choose Your Own Adventure. In these books
and games, the user is presented with a scenario and asked to make a 
decision. For example, Imagine you are standing outside a castle and
you are being chased by a dragon. 

Do you want to: fight (d)ragon, (s)torm castle, (g)o home?

where, as the user, you would select "d" to fight the dragon, "s" to
storm the castle, and "g" to go home. Depending on the user's selection,
you would turn to a different page in the book, or in the video game, a
different block of code would run. This is another example of an if
conditional, but instead of looking at the value of a number, you're 
using a letter.
'''
my_str = input("Do you want to fight (d)ragon, (s)torm castle, (g)o home?: ")
if my_str == "d":
	print("You lose")
elif my_str == "s":
	print("have fun storming the castle")
elif my_str == "g":
	print("wimp")
else:
	print("not a valid selection")
'''
The first line gets input from the user. Since we're using the input
function, the type of my_str will be a string. We then use my_str in the
conditionals. In the line if my_str == "d", we're checking if my_str is
a "d". Notice that we use the "". This tells Python that we want to 
check for the letter d and not a variable called d. Also notice the ==, 
when checking for equality, you always use the == instead of the =. The
single = will assign a value, which is not what you want here. 

The rest of the code proceeds in the same way as if we were using numbers.
If my_str is a "d", the "You lose" will print. If it's not a "d", then
the next elif is evaluated, and so on. If my_str does not equal any of
the given strings, then the else block will execute and "not a valid 
selection" will print. This "not a valid selection" is how we handle
bad input.
'''
'''
Class exercise: change the code above to include another option:
(c)ross the flood waters that will print "Good luck" if "c" is selected.
'''
'''
Conditionals can also include multiple conditions on multiple variables.
You may want to check if a < 0 or a > 10. There is no way to do this by 
checking that a is between two numbers because the accepted range on a 
is discontinuous.

There are another type of operators called boolean operators that are
used to have multiple conditions. The boolean operators we'll talk about
here are AND and OR. 

For example,
'''
a = 12
if a < 0 or a > 10:
	print("a is good")
else:
	print("a out of range")
'''
In this example, the a < 0 is evaluated and determined whether it is 
true or false. Next, the second part, a > 10, is evaluated and 
determined whether it is true or false. If either of these expressions is
true, then the whole statement is true and the code in the if block
will execute.

Notice that the OR is used in this example. This is because a can't
satisfy both conditions, it can't be both < 0 and > 10. No number meets
both conditions. 

For the "or" operator, the truth table looks like:
T or T = T
T or F = T
F or T = T
F or F = F

With an "or" only one of the expressions must be true in order for the
entire condition to be true.

The other boolean operator is the AND operator. This operator is used 
when both conditions need to be true, not just one or the other.

For example, if there are two variables and the value of each needs to
meet a certain condition. 

The truth table for the "and"
looks like:
T and T = T
T and F = F
F and T = F
F and F = F

where the T and F represent the truth value of the expression being 
evaluated. 
'''	
a = 5
b = 10
if a < 10 and b > 0:
	print("both are true")
else:
	print("something is false")
'''
In this case, it needs to be true that both a < 10 and b > 0. If either
of these conditions is not true, then the whole expression is not true
'''

'''
Class exercise
For example, back to the Subaru example, say you wanted to check both mpg and CO2PerYear
if mpg < 15 and CO2PerYear > 15000, then print "Biggest polluter ever"
Otherwise, print("Not bad")

The answer is in Lecture7SubaruIf3.py, but don't look at it until you've
worked through the code.

'''

'''
Let's look at how we could use our earlier choose your own adventure code
to force the user to enter a valid selection. With the if statement, we
could only check one time, and if the user entered something invalid, we
could print a message saying "Invalid selection", but there was no way 
to ask again. What we really want to do is ask over and over and over
again until they enter a valid choice. That code would look something 
like this
'''
#Start with two options only and check that user input is one of those
my_str = raw_input("Do you want to fight (d)ragon or (g)o home?: ")
#if my_str is not "d" and it's not "g", then go into the loop
while my_str != "d" and my_str != "g":
	print "not a valid selection"
	#update my_str by asking again, prepares us for going through the loop again
	my_str = raw_input("Do you want to fight (d)ragon or (g)o home?: ")
#At this point, we've received a valid selection because we're not in
#the loop, so we know my_str must be either "d" or "g"	
if my_str == "d":
	print "You lose"
else: #if it's not "d", it must be "g"
	print "wimp"

'''
There are multiple conditions being checked and both conditions need to 
be true in order for the while loop to run. It must be true that my_str 
is not "d" and my_str is also not "g". If it is true that either my_str 
is "d" or my_str is "g", then the user has made a valid entry and there 
is no need to ask again.

In the above example, the expressions are my_str != "d" and
my_str != "g".

'''

'''
There is another kind of loop that is similiar to the while loops that is
used to iterate through a collection of items. You can also think of this
as looping over a collection, where each time through the loop, a 
different item in the collection is being evaluated. This type of loop
is called an iterator and in Python it uses the keyword "for".

An example:
'''
for letter in "hello world":
	print(letter)
'''
In that example, the variable "letter" takes on the properties of each
item in the collection, in order. The collection in this case is the 
string "hello world". The first time through the loop, the
value of letter is "h", the second time it is "e", the third time it is
"l", and so on, until the end of the collection is reached. This type of
loop will execute a fixed number of times, unlike the while loop which
will execute as long as the looping condition is true.

The variable "letter" is an arbitrary name, there's nothing special about
it. We could use 
'''
for puppies in "hello world":
	print(puppies)
'''
and achieve the same result. It's noteworthy here that the iterator 
variable, the letter and puppies in these examples, takes on the same
type as the type of the collection. In this case, they're strings.

Another type of collection is a sequence of numbers, such as 1,2,3,4,5.
Python has a built-in command for generating sequences of a specified
length called range.
'''
numbers = range(1,6)
'''
numbers contains 1,2,3,4,5. The upper value is not included in the 
sequence, but the lower value is.
'''

print(numbers)
'''
To iterate through the collection, you do the same thing as when you 
iterate over a collection of letters. In the example here, the value of
x each time through the loop is one of the items in numbers, one at a 
time, in order. The first time through the loop, x = 1, the second time,
x = 2, and so on.
'''
for x in numbers:
	print(x)
	
#We could also do something to the x variable in the loop, such as x * 2
for x in range(1,6):
	print(x * 2)
	
'''
One of the other collection types we saw was a list. In a list, it's a 
collection of items that can be of different types and we can iterate
over the list in the same way that we iterate over a string or a sequence
of numbers.
'''
myList = ['a', 2, 'puppies', 4]
for item in myList:
	print(item)

'''
You can also iterate over a collection by using the index of each item
in the collection. One way to do this is to incorporate the range command
into the for loop and use the range item as the index into the list
'''
for x in range(0,4):
	print(myList[x])
'''
In this example, the x will be a value in the sequence 0,1,2,3 in order,
so x can be used as the index of myList.

When you iterate over a collection, it's because you want to know
something about the items in the collection, or modify items in some
ways.


