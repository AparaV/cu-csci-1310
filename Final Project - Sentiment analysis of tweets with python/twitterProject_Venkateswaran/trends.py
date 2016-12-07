import os
import sys
import json
import string #for parsing string
from state import load_states
from country import Country
from parse import load_sentiments
from colors import get_sentiment_color
from tweet import Tweet
from geo import GeoPosition
	
punctuation = list(string.punctuation)
punctuation.remove('#')
punctuation.remove('@')
	
class SentimentAnalysis:
	
	def __init__(self):
		self.sentiments = load_sentiments()
		self.states = load_states()
		self.tweets = []
		self.stateScores = self.initScores()
    
	def showCountry(self):
		self.usa = Country(self.states, 1200)
		self.colorState()
	
	def analyzeData(self, files, queries):
		self.filterTweets(files, queries)
		self.computeSentiment()
	
    #Filter all tweets in given file containing the query
	def filterTweets(self, files, queries):
		for File in files:
			with open(File, "r") as f:
				for line in f:
					try:
						tweet = json.loads(line)
						msg = tweet['text']
						pos = GeoPosition(tweet['coordinates'][1], tweet['coordinates'][0])
						time  = tweet['created_at']
						thisTweet = Tweet(msg, time, pos)
						for query in queries:
							query = query.lower()
							if (query in self.parseTweet(msg)) and (thisTweet not in self.tweets):
								self.tweets.append(thisTweet)
					except ValueError:
						print "error occured - file corrupt"
	
	#Compute Sentiment score
	def computeSentiment(self):
		for tweet in self.tweets:
			score = []
			words = self.parseTweet(tweet.message())
			for word in words:
				if word in self.sentiments:
					score.append(self.sentiments[word])
			avgScore = 0
			if len(score) != 0:
				avgScore = sum(score) / float(len(score))
			state = self.closestState(tweet.position())
			self.stateScores[state].append(avgScore)
		self.averageSentiments()
	
	def colorState(self):
		for state, sentiment in self.stateScores.items():
			stateColor = get_sentiment_color(sentiment)
			self.usa.setFillColor(state, stateColor)
	
	#find closest state
	def closestState(self, pos):
		minDist = 9999999999
		closest = ""
		for state in self.states:
			currDist = state.centroid().distance(pos)
			if currDist < minDist:
				minDist = currDist
				closest = state.abbrev()
		return closest
	
	#initialize sentiment scores
	def initScores(self):
		scores = {}
		for state in self.states:
			scores[state.abbrev()] = []
		return scores
	
	#average sentiment scores for each state
	def averageSentiments(self):
		for state in self.stateScores:
			stateScore = self.stateScores[state]
			if len(stateScore) != 0:
				avg = sum(stateScore) / float(len(stateScore))
				self.stateScores[state] = avg
			else:
				self.stateScores[state] = None		
	
	#function to split tweet into meanignful (or not) words
	def parseTweet(self, tweet):
		for char in punctuation:
			tweet = tweet.replace(char, " ") #remove all punctuation
		words = tweet.split() #remove all whitespaces
		newWords = []
		for word in words:
			newWords.append(word.lower())
		return newWords
	
	#debug code
	def printTweets(self):
		for tweet in self.tweets:
			print tweet.message()
	
if __name__ == "__main__":
	if len(sys.argv) > 1:
		query = ' '.join(sys.argv[1:])
		queries = query.split()
		print queries
	else:
		print "error"
	
	fname1 = os.path.join('tweets', 'tweets_with_time.json')
	fname2 = os.path.join('tweets', 'tweets_with_time_2.json')
	fname3 = os.path.join('tweets', 'tweets_with_time_3.json')
	fname4 = os.path.join('tweets', 'tweets_with_time_4.json')
	
	files = [fname1, fname2, fname3, fname4]
    
	sa = SentimentAnalysis()
	sa.analyzeData(files, queries)
	sa.showCountry()
