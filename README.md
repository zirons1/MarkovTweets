# Markovian Tweet Generator

## Project Description
This project takes in a Twitter user's handle and outputs a tweet in the style of that user.

### Twitter API
This application is registered under a Twitter Developer account. 
The Python file `json_reader.py` records up to 3200 tweets by using Twitter's API and the Python library tweepy.
This application is compatible with Twitter's extended tweet format of 280 characters.

### Markov Chains
This application uses [Markov Chains](https://en.wikipedia.org/wiki/Markov_chain) to generate text realistic to the specified user.
The tweets recorded from `json_reader.py` are saved into a .txt file, parsed by the C++ file `markov.cc`, and stored in a map data structure.
The map data structure is traversed until an end line character is found or the tweet becomes too long.

### Running the Code
Running this code requires a Twitter Developer's license with consumer keys and authentivation tokens.
To run this code compile `json_reader.py` and add the Twitter user's handle as a command line argument as shown below.
```
python json_reader.py [handle]
```
Then compile `markov.cc` and execute the file as shown below. 
Once `markov.cc` is compiled the executable can be executed a many times as desired and produce a unique tweet.
```
g++ markov.cc -o new_tweet
./new_tweet
```
