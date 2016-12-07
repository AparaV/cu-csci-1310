'''
StringsAndLists.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2016
'''

'''
Strings and lists are two types of variables in python that store a 
collection of data. The entire collection is the variable. For example,
if I had a deck of cards, you can think of that as a collection of cards.
The entire collection would be seen as the variable, such as a list of
the face values of each card in the deck.

Strings are a collection of letters, numbers, and symbols. 
We've already worked with strings when we get input from the user, 
either using the input command or a command-line argument.

When we looked at numbers, there were operations that we were interested
in, such as +, -, *, /. The same is true when we look at collections.
There are operations on the collection, such as finding individual 
elements, or looking at half of the elements, or putting the elements
in order. These are things that people frequently want to do with 
collections, and so to make our lives easier, python has created this
functionality for us. We just have to know what the command is called to
do what we want to do.

The ability to search through strings for a given word or phrase is 
extremely useful. There is a command called find that will
return the index of the item we're searching for.

Things that are represented as strings:
DNA sequences
Your name
Words in a book, either the individual words or the entire word

How would you:
Count the number of times someone said a particular word in a show, or
a novel?
Count the most common words in your favorite novel?
Find genes in a sequence of DNA?
Play a game of mad-libs and replace <noun> with an actual noun?

'''

'''
To demonstrate how we could access one or more items in a string:
we'll start with a word
'''

my_str = raw_input("type a word: ")
print my_str
#you can check individual values of a string using an index into the string
#for example, if you want to get the first element of my_str
print my_str[0]
#notice that the indexing starts at 0
#this gets the third element of the string
print my_str[2]
'''how long is your name? If it's a string, you can use len() to
get the number of characters in the string'''

'''
len() is a command that is built-in to python. In the python program,
there is a definition for len() that probably counts the bytes of 
memory used by the string and that's its length. But, we don't want to
have to do that, so we can just use what's being done for us.
'''

le = len(my_str)
print le

'''
A string is a sequence, and as such, there are subsequences within the
sequence. Python calls this a slice. To access a subsequence, you use 
the : to indicate a range of indices to access. 

For example, to access the third and fourth items, 
'''
new_str = my_str[2:4]
print new_str
'''
The syntax there is the lower index is included and the upper index is 
not. new_str includes my_str[2] and my_str[3], but not my_str[4]

Another option for accessing a subsequence is to specify a starting index,
but not an ending index, such as
'''
print my_str[2:]
'''
Doing my_str[2:] will start at my_str[2] and go to the end of the string

Or, go the other way and get everything from the beginning, up to a 
specified index-1
'''
print my_str[:4]

print my_str[:]

'''
Let's turn now to the DNA examples and search a DNA 
string for the presence of a codon. Computational scientists work with
computer representations of DNA searching for patterns. There are 
lab experiments with real DNA and those results can then be analyzed
computationally. 

Assume we have the following DNA string:

'''
DNA = "ACCAATCTATCA"
'''
and we're searching for CAA, the codon for Glutamine. We want to find
the index in DNA for the start of CAA. 

String Methods:
We turn to methods on objects,
where the string is the object. For example, there is a method called
"find" that can be used to find a given item in the string. The
method will produce a value that is the index of where that item was
found. The syntax looks like:
'''
i = DNA.find("CAA")
print "CAA found at: ",i
'''
We've introduced some new notation here, the . following the name of the
variable. This is called "dot notation". There's another example using 
the count method that enables us
to count the number of times a given item is found. For example, let's 
change DNA to include multiple instances of CAA 

'''
DNA = "ACCAACAAT"
i = DNA.count("CAA")
print "there are ", i, "instances of CAA"

'''and if we change DNA to be different, we should see the count produce
a different result'''

'''
You can think of the methods as a block of code that has already been
written, much like the print command. It's functionality built into Python.
Each type of data has different methods associated with it. Strings have
methods such as find and count, they also have methods such as upper 
and lower that could be used as follows:
'''
dna = DNA.lower()
print dna
DNA = dna.upper()
print DNA
'''
Notice that the upper and lower have (), but nothing is in the (). In the
case of count, we needed to know what to count. The "CAA" was the argument
to the count method, and told count what it was counting. Those are the 
values needed for the program to run 
correctly. If we didn't have anything in count, the method wouldn't know
what needed to be counted. But with upper and lower, there's no additional
information needed to make the method work, we just want to make the string
upper case or lower case, so we just have empty () on the methods.

In DNA strings, the ATG codon generally signifies the start of a gene,
and one of the tricks in string searching is to identify those ATG triplets
in a long string. 

exercise: If you were given AAGTCATGCCCGGGTTCGGA, how would you identify
the ATG and then use that information to generate a new string that
represents the gene and includes the ATG and everything to the end of 
the string? Next, count the instances of GGA and GGG in the gene. Answer
is in Lecture6GeneFind.py

Next, let's make a small change to DNA to make it AAGTCATGCCCGGGATCGGA.
Rerun your code, what happened and why? Answer is at the bottom of this
file, but don't look at it until you've worked through the problem.
'''

'''
There are many other string processing methods that allow us to do things
such as replace items in a string with other items, such as

'''
myStr = "Four score and seven years ago"
myStr = myStr.replace("seven", "many")
print myStr

'''or introduce genetic mutation'''
DNA = "ATGCCATGCTATGGG"
DNANew = DNA.replace("A","T")
print "Original: ", DNA, " New: ", DNANew

'''
Or, split a string into many pieces using some criteria. We can split 
on blank spaces to count the
words. Here, let's split on " " in the myStr.
'''
wordList = myStr.split(" ")
print wordList
'''
There are other string processing and formatting commands that are 
useful for displaying strings. We've seen one already when we print
floats to the screen:
'''
f = 4.5678
print "formatted float: %.2f" %f

'''
There's another way of formatting strings using the format command. It
looks like:
'''
print("formatted float {:.2f}".format(f))
'''
The {} can be used to indicate both spacing and decimal precision. For
example, using {:8.2f} will put 8 spaces in front of the printed
variable:
'''
print("formatted float {:8.2f}".format(f))
'''
This same formatting approach can be used for strings and integers to 
put space in the printing:
'''
print("DNA {:>20s} ".format(DNA))
'''
The s indicates that the variable being printed is a string. The 20 is 
the size of the printing block, and the > says make it right justified.
This will cause the string to be printed with blank space to the left
of the string that fills in the space to make it 20 characters long.
'''
'''
There are other formatting that you can do on strings, such as adding
tabs to space things evenly, or forcing a new line in the printing.
'''
myStr = "This is a test string"
print(myStr)
myStr = "This \t is \t a \t test \t string"
print(myStr)
myStr = "This is a \n\n\ntest string"
print(myStr)
 
