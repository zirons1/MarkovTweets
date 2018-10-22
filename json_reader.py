import tweepy
import json
import sys

file = open("tweets.txt", "w")

consumer_key = 'XXXXXXXXXXXXXXXXXXXX'
consumer_secret = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
access_token = 'XXXXXXXXXX-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
access_token_secret = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)

tweet_counter = 0

handle = str(sys.argv[1])

counter = 0
tweets = api.user_timeline(screen_name=handle, count=200, include_rts = False, tweet_mode='extended')

while(counter < 15):
	last = {}

	for tweet in tweets:
		tweet_counter += 1
		file.write(tweet.full_text.encode("ascii", "ignore"))
		file.write("\n")
		last = tweet
	last_id = last.id_str

	counter += 1
	tweets = api.user_timeline(screen_name=handle, count=200, max_id=last_id, include_rts = False, tweet_mode='extended')

print("Tweets Ingested: " + str(tweet_counter))
