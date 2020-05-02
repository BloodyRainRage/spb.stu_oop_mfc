#include "pch.h"
#include "Mylib.h"
#include <fstream>
#include <iostream>

vector<users> Mylib::loadFile(CString filepath) {

	vector<users> result;	
	string tmp;	

	ifstream inputFile(filepath);
	while (getline(inputFile, tmp)) {
		
		string delimiter = ";";
		size_t pos = 0;
		int iteration = 0;
		std::string token;
		users user;
		while ((pos = tmp.find(delimiter)) != std::string::npos) {
			token = tmp.substr(0, pos);
			switch (iteration) {
			case 0: 
				user.username = token;
				break;				
			case 1:
				user.firstname = token;
				break;
				
			case 2:
				user.lastname = token;
				break;
			case 3:
				user.email = token;
				break;	
			case 4:
				user.password = token;
			}
			tmp.erase(0, pos + delimiter.length());
			iteration++;
		}
		user.position = tmp;
		if (iteration != 5) {
			iteration = 0;
			continue;
		}
		result.push_back(user);
		iteration = 0;
		
	}

	return result;

}

//Get vector of lines using normal type
vector<string> Mylib::loadFile(string filepath) {

	vector<string> result;	
	string tmp;	

	ifstream inputFile(filepath);
	while (getline(inputFile, tmp)) {
		result.push_back(tmp);
		cout << tmp << endl;
	}

	return result;

}

//save string to file 
void Mylib::saveFile(string path, string toStore) {
	
	ofstream output;
	output.open(path);

	output << toStore;
	
	output.close();

}

//save CString to file
void Mylib::saveFile(CString path, string toStore) {
	
	ofstream output;
	output.open(path);

	output << toStore;
	
	output.close();

}