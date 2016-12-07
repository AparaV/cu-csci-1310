'''
Lecture5Mins.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2015
'''
seconds = 200
#dividing seconds by 60 will give you the number of minutes
#and, you can get rid of fractional minutes by casting as an int
mins = int(seconds / 60)
#to get how many seconds, you want the modulus of dividing by 60
#this is the fractional seconds in a minute leftover
s = seconds % 60
print "200 seconds is",mins, "mins and", s, "seconds"
