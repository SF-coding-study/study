#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "PhoneBook.hpp"

// 연락처 정보 입력
Contact createNewContact() {
	Contact newContact;
	string firstName, lastName, nickname, phoneNumber, memo;

	cout << "Enter First Name: ";
	cin >> firstName;
	cout << "Enter Last Name: ";
	cin >> lastName;
	cout << "Enter Nickname: ";
	cin.ignore();
	getline(cin, nickname, '\n');
	cout << "Enter Phone Number: ";
	cin >> phoneNumber;
	cout << "Enter Memo: ";
	cin.ignore();
	getline(cin, memo, '\n');

	newContact.setContact(firstName, lastName, nickname, phoneNumber, memo);
	return newContact;
}

// 연락처 추가
void addCommand(PhoneBook& phoneBook) {
	Contact newContact = createNewContact();
	phoneBook.addContact(newContact);
}

// 연락처 검색 기능
void searchCommand(PhoneBook& phoneBook) {
	phoneBook.displayContacts();

	int index;
	std::cout << "상세 정보를 확인하려면 인덱스를 입력하십시오: ";

	// index 외의 값이 들어왔을 경우 처리
	if (!(cin >> index)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "잘못된 입력입니다. 유효한 숫자를 입력하십시오." << endl;
		return;
	}

	phoneBook.displayContactsDetails(index);
}

// 명령을 처리
void processCommand(const string& command, PhoneBook& phoneBook) {
	if (command == "ADD") {
		addCommand(phoneBook);
	}
	else if (command == "SEARCH") {
		searchCommand(phoneBook);
	}
	else if (command == "EXIT") {
		std::cout << "프로그램을 종료합니다." << std::endl;
		exit(0);  // 프로그램 종료
	}
	else {
		std::cout << "잘못된 명령입니다." << std::endl;
	}
}

// 프로그램 실행
void runPhoneBook() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "명령어를 입력하십시오. (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		processCommand(command, phoneBook);
	}
}

int main() {
	runPhoneBook();
	return 0;
}