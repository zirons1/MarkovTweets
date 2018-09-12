#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//Testing using system calls inside the code and piping output to text file to read later
int main(){
	string FILE_NAME = "text.txt";
	
	system((string("pwd >> ") + FILE_NAME).c_str());
	
	string line;
	
	ifstream myfile ("text.txt");
	
	if (myfile.is_open()){
		while ( getline (myfile,line) ){
			cout << line << '\n';
		}
    myfile.close();
	}
	
	system((string("rm ") + FILE_NAME).c_str());
}
