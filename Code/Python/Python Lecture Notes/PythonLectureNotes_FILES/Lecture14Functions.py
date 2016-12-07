#restructuring recitation 4 using functions
'''
In recitation 4, you wrote a program that simulated a coin flip X times,
where X was an input from the user. The random nature of the coin flip
was represented using the random functionality in python, where you could
generate a random number between 1 and 50 and if the number was > 50,
then the coin was a heads, and if it was 50 or less, the coin was a 
tails.

Restructure the code to write a function that flips a coin one time.
What do you need for your one flip?

Are there arguments to your function?
Is there a return value?

One approach is to return a string heads if the flip is heads and tails
if the flip is tails.

You still need to generate a random number, but now I'm only generating
one random number. What's nice about doing the coin flip in a function
is that you hide how the outcome is actually determined. You don't show
that there's a random number. The user can just call a function called
flipCoin and handle the result.
'''
import random
def flipCoin():
	#chance is a local variable. It can only be seen inside the function
	chance = random.randint(1,100)
	#flip could also be a 0 or 1
	if chance > 50:
		flip = "h"
	else:
		flip = "t"
	return flip

#what does updateCash need to work
#what needs to be returned from updateCash
def updateCash(cash, guess, outcome):
	if guess == outcome:
		cash = cash + 5
		print "you win"
	else:
		cash = cash - 5
		print "you lose"
	return cash
	
def main():
	flips = input("How many times would you like to flip coin?")
	heads = 0
	tails = 0
	
	cash = 100 #initial amount of money that the user has
	for i in range(0,flips):
		guess = raw_input("Enter h for heads and t for tails")

		outcome = flipCoin() #no arguments needed
		if outcome == "h":
			heads = heads + 1
		else:
			tails = tails + 1
		cash = updateCash(cash, guess, outcome)

	print cash		
	print "Flipping",flips,"coins"
	print "Got",heads,"heads and",tails,"tails"

#program execution starts here
main()
