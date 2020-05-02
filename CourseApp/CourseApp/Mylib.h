#pragma once
#ifndef MYLIB_H
#define MYLIB_H
#include <vector>
#include <string>


using namespace std;

struct users {
	string username;
	string firstname;
	string lastname;
	string email;
	string password;
	string position;
public:
	string getUser() {
		return "Username: " + username + "\r\n" +
			"First name: " + firstname + "\r\n" +
			"Last name: " + lastname + "\r\n" +
			"email: " + email + "\r\n" +
			"password: " + password + "\r\n"
			"position: " + position + "\r\n";

	}
};


class Mylib {

public:
	vector<users> loadFile(CString filepath);
	vector<string> loadFile(string filepath);
	void saveFile(string path, string toStore);
	void saveFile(CString path, string toStore);

	void display();


};




#endif // !MYLIB_H