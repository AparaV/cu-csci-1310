#python program to read wunderground api and get forecast data
'''
forecast data collection and simulation model
Steps
1. Collect forecast data using cron job to determine accuracy of forecast
Data collected includes temps, wind, humidity, precip for three days from
current day.

2. Compare forecast for day t to actual on day t to develop simulation 
parameters - distribution of days for a simulated growing season and 
the weather on those days.

'''

import datetime
import requests
import json
#class forecastData
#private
#	current day - month, day, year of the forecast
#	request object
#	data string to write to file
#	file name
#public
#	writeForecastToFile
class ForecastData(object):
	def __init__(self, connectionString, f):
		res = requests.get(connectionString)
		#print res.text
		self.jsonData = res.json() 
		now = datetime.datetime.now()
		self.year = now.year
		self.month = now.month
		self.day = now.day
		self.filename = f
		
	def writeForecastToFile(self):
		#open the file
		dataFile = open(self.filename, 'a+')
        #jsonData includes four days of forecasts as default
		for day in self.jsonData['forecast']['simpleforecast']['forecastday']:
			#print json.dumps(day, indent=3, sort_keys=True)
			dataFile.write((str(self.month) + "-" + str(self.day) + "-" + str(self.year) + "," +
				str(day['date']['month']) + "-" + 
				str(day['date']['day']) + "-" + 
				str(day['date']['year']) + "," + 
				"H:" + day['high']['fahrenheit'] + "," + "L:" + day['low']['fahrenheit'] + "," +
				str(day['avehumidity']) + "," + str(day['avewind']['mph']) + "," + str(day['avewind']['dir']) +
				"," + str(day['maxwind']['mph']) + "," + str(day['maxwind']['dir']) + "," + str(day['qpf_allday']['in']))+"\n")
		dataFile.close()

#collecting data for multiple cities
fdBoulder = ForecastData('http://api.wunderground.com/api/27b6ac5d4b620d0c/forecast/q/CO/Boulder.json', "boulderData")
fdBoulder.writeForecastToFile()

fdSeattle = ForecastData('http://api.wunderground.com/api/27b6ac5d4b620d0c/forecast/q/WA/Seattle.json', "seattleData")
fdSeattle.writeForecastToFile()

fdChicago = ForecastData('http://api.wunderground.com/api/27b6ac5d4b620d0c/forecast/q/IL/Chicago.json', "chicagoData")
fdChicago.writeForecastToFile()

fdBaltimore = ForecastData('http://api.wunderground.com/api/27b6ac5d4b620d0c/forecast/q/MD/Baltimore.json', "baltimoreData")
fdBaltimore.writeForecastToFile()

		#print jsonData['forecast']

		#parsed = json.loads(jsonData)
		#print json.dumps(jsonData, indent=3, sort_keys=True)
