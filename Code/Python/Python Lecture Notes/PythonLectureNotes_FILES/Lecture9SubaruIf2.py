'''
Lecture9SubaruIf2.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2015
'''
milesPerYear = raw_input("How many miles a year do you drive? ")
mpg = raw_input("How many mpg does your car get? ")
milesPerYear = int(milesPerYear)
mpg = int(mpg)

if mpg > 30:
	print "Nice job"
elif mpg > 15:
	print "Not great, but okay"
else:
	print "Bad, very, very bad"

lbsCO2 = 19.4
CO2PerYear = milesPerYear*lbsCO2/mpg
	
print "CO2 per year: ",CO2PerYear


