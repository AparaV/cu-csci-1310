'''
Assignment 7
Aparajithan Venkateswaran
TA: Camilla Lambrocco
Recitation - 101
'''
import random

#Predefined place-holders
placeHolders = ['<adjective>', '<another adjective>', '<noun>', '<another noun>', '<plural noun>',
				'<relative>', '<time of day>', '<verb>']

#Open file and transfer data to a local list
try:		 
	myFile = open("Templates.txt", "r")
	templates = myFile.readlines();#Creates list from the lines in the file
#If file not found, use default templates
except IOError:
	print "File not found. Using default templates\n"
	templates = ["It was the <adjective> of the <noun>, it was the <another adjective> of the <another noun>.",
				 "Be kind to your <noun>-footed <plural noun>, or a duck maybe somebody's <noun>.",
				 "<plural noun>? I don't have to show you any <adjective> <plural noun>!",
				 "My <relative> always said <noun> was like a box of <plural noun>. You never know what you're gonna get.",
				 "One <time of day>, I <verb> a <noun> in my pajamas. How he got in my pajamas, I don't know."]


#Begin Playing Game
while True:
	
	#Ask whether user actually wants to play
	playing = raw_input('Do you want to play the game? (y) or (n)\n')
	#If no, then break the loop
	if str(playing) == "n":
		break
	#If it is not "n" or "y", it is an invalid choice. So ask again
	if str(playing) != 'y':
		print 'Enter a valid choice\n'
		continue
	
	i = random.randrange(0,4) #Generate random number
	temp = templates[i] #Create a temperory string to store the current template
	
	#Check for all place-holders, ask user input, and replace
	for k in placeHolders:
		if temp.find(k) != -1:
			a = raw_input("Enter " + k[1:len(k) - 1] + ": ")
			temp = temp.replace(k, a)

	#Print the new story
	print temp
	print '\n'

#End Game
print '\n\nGoodbye!'
