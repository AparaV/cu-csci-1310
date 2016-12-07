'''
File is "stateCapitals.txt"
'''

f = open('stateCapitals.txt', 'r')

states = {}

for line in f:
	line = line.strip()#remove new lines
	#print line
	data = line.split(',')
	#print data
	#states[data[0]] = data[1]#.strip()
	states[data[0]] = {}
	states[data[0]]['capital'] = data[1].strip()
	states[data[0]]['abbrv'] = data[2].strip()
	states[data[0]]['year'] = data[3].strip()
	
#print states

for key in states:
	for val in states[key]:
		print key, states[key][val]


#if "New York" in states:
#	print "Captial of NY is", states['New York']
