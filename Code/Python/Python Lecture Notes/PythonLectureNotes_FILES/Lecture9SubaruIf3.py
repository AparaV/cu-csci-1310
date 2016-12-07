'''
Lecture9SubaruIf3.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2015
'''
milesPerYear = raw_input("How many miles a year do you drive? ")
mpg = raw_input("How many mpg does your car get? ")
milesPerYear = int(milesPerYear)
mpg = int(mpg)

lbsCO2 = 19.4
CO2PerYear = milesPerYear*lbsCO2/mpg

#notice that this if statement goes after CO2PerYear has been calculated
if mpg < 15 and CO2PerYear > 15000:
	print "Biggest polluter ever"
else:
	print "Not bad"
	
print "CO2 per year: ",CO2PerYear




