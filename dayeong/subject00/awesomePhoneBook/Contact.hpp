#pragma once
#include <string>

using namespace std;

class Contact
{
private:
	string firstName;
	string lastName;
	string phoneNumber;
	string nickname;
	string memo;

public:
	void setContact(const string& firstName, const string& lastName, const string& phoneNumber, const string& nickname, const string& memo);

	string getFirstName() const;
	string getLastName() const;
	string getPhoneNumber() const;
	string getNickname() const;
	string getMemo() const;
};