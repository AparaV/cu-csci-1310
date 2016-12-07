#Basketball Algorithm
#Aparajithan Venkateswaran
#Recitation 11 - REC: 101

def isLeadSafe(differenceOfPoints, secondsLeft, hasBall):
	
	s = differenceOfPoints - 3;
	
	if hasBall == 1:
		s += 0.5
	else:
		s -= 0.5
		
	if s < 0:
		s = 0
		
	s *= s
	
	if s > secondsLeft:
		return True
	else:
		return False

def main():
	
	#get input
	points = raw_input("Difference of Points: ")
	time = raw_input("Time left: ")
	hasBall = raw_input("has ball (1 = yes; 0 = nope): ")
	
	#type casting
	points = float(points)
	time = float(time)
	hasBall = int(hasBall)
	
	if isLeadSafe(points, time, hasBall) == True:
		print "safe"
	else:
		print "danger"
		
main()
