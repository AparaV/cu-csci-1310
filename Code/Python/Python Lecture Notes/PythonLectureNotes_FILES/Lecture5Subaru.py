'''
Lecture5Subaru.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2015
'''
#get miles and mpg as inputs from the user
milesPerYear = eval(raw_input("How many miles a year do you drive? "))
mpg = eval(raw_input("How many mpg does your car get? "))
	
#declare lbsCO2 variable used in next line
lbsCO2 = 19.4
#calculate CO2PerYear
CO2PerYear = milesPerYear*lbsCO2/mpg
print "CO2 per year:",CO2PerYear

'''print result. There's a format specifier here to truncate decimals
We haven't talked about format specifiers yet. But if you're interested
in what's happening with this command, google "python format specifier"
for more information. You may also find in your search that there is 
another way of doing this formatting using a command called format.
'''
print "CO2 per year: %.2lf" %CO2PerYear


