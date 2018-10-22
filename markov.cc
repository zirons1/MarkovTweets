#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void split(const string &s, char c, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, c)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char c) {
    vector<string> elems;
    split(s, c, elems);
    return elems;
}

bool remove_chars(char c){
    switch(c){
    case '!':
    case '?':
    case '"':
	case '(':
	case ')':
	case '*':
	case ' ':
	case '.':
        return true;
    default:
        return false;
    }
}

int main(){
	srand(time(NULL));
	
	typedef map<string, vector<string> > WordMap;
	
	WordMap word_map;
	
	ifstream file ("tweets.txt");
	string line;
	
	if (file.is_open()){
		while(getline(file, line)){
			if (line.length() > 0){				
				string prev = "";
				int index = 0;
				int counter = 0;
				
				vector<string> words = split(line,' ');
				
				words[0].erase(remove_if(words[0].begin(), words[0].end(), &remove_chars), words[0].end());
				word_map[""].push_back(words[0]);						
							
				for (int j = 1; j < words.size(); j++){
					words[j].erase(remove_if(words[j].begin(), words[j].end(), &remove_chars), words[j].end());
					word_map[words[j-1]].push_back(words[j]);
				}
				
				word_map[words[words.size() -1]].push_back(".");
			}
		}		
		file.close();
	}

	for (int i = 0; i < word_map[""].size(); i++){
		if (word_map[""][i] == "."){
			word_map[""].erase(word_map[""].begin()+i);
		}
	}
	ofstream map ("tweet_map.txt");
	
	WordMap::iterator pos;
		
    for (pos = word_map.begin(); pos != word_map.end(); ++pos) {
			
		map << "key: " << pos->first << endl;
		map << "values: ";
        for (int j = 0; j < pos->second.size(); j++){
			map << pos->second[j] << ", ";
		}
		map << "\n\n";
    }
	
	string start = "";	
	string output = "";
	
	while(true){		
		vector<string> next_words = word_map[start];
		
		string new_word = "";
		if (next_words.size() > 0){
			new_word = next_words[rand() % next_words.size()];
		}else{
			break;
		}		
		start = new_word;
		
		if ((new_word == ".") || (output.length() + new_word.length() > 280)){
			break;
		}else{
			if (output.length() > 0){
				output += " " + new_word;
			}else{
				output += new_word;
			}
		}
	}
	
	cout << output << endl;
}








