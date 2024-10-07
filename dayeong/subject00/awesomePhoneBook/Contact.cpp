#include <iostream>
#include "Contact.hpp"

using namespace std;

void Contact::setContact(const string& firstName, const string& lastName, const string& nickname, const string& phoneNumber, const string& memo){
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->memo = memo;
}

string Contact::getFirstName() const {
    return firstName;
}
string Contact::getLastName() const {
    return lastName;
}
string Contact::getPhoneNumber() const {
    return phoneNumber;
}
string Contact::getNickname() const {
    return nickname;
}
string Contact::getMemo() const {
    return memo;
}