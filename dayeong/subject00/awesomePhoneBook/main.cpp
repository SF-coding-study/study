#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "PhoneBook.hpp"

// ����ó ���� �Է�
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

// ����ó �߰�
void addCommand(PhoneBook& phoneBook) {
	Contact newContact = createNewContact();
	phoneBook.addContact(newContact);
}

// ����ó �˻� ���
void searchCommand(PhoneBook& phoneBook) {
	phoneBook.displayContacts();

	int index;
	std::cout << "�� ������ Ȯ���Ϸ��� �ε����� �Է��Ͻʽÿ�: ";

	// index ���� ���� ������ ��� ó��
	if (!(cin >> index)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�߸��� �Է��Դϴ�. ��ȿ�� ���ڸ� �Է��Ͻʽÿ�." << endl;
		return;
	}

	phoneBook.displayContactsDetails(index);
}

// ����� ó��
void processCommand(const string& command, PhoneBook& phoneBook) {
	if (command == "ADD") {
		addCommand(phoneBook);
	}
	else if (command == "SEARCH") {
		searchCommand(phoneBook);
	}
	else if (command == "EXIT") {
		std::cout << "���α׷��� �����մϴ�." << std::endl;
		exit(0);  // ���α׷� ����
	}
	else {
		std::cout << "�߸��� ����Դϴ�." << std::endl;
	}
}

// ���α׷� ����
void runPhoneBook() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "��ɾ �Է��Ͻʽÿ�. (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		processCommand(command, phoneBook);
	}
}

int main() {
	runPhoneBook();
	return 0;
}