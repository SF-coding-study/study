#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

using namespace std;

PhoneBook::PhoneBook(size_t maxSize) : maxSize(maxSize) {}

// ����ó �߰�
void PhoneBook::addContact(const Contact& newContact) {
	if (contacts.size() >= maxSize) {
		cout << "��ȭ��ȣ�ΰ� ���� á���ϴ�.���� ������ ����ó�� �����˴ϴ�." << endl;
		contacts.pop();
	}
	contacts.push(newContact);
	cout << "���ο� ����ó�� �߰��Ǿ����ϴ�." << endl;
}

// ��� ���ڿ� ����
string formatString(const string& str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

// ����ó ��� ǥ��
void PhoneBook::displayContacts() const {
	if (contacts.empty()) {
		cout << "����� ����ó�� �����ϴ�." << endl;
		return;
	}

	queue<Contact> tempQueue = contacts;
	int index = 0;

	cout << setw(10) << "Index" << "|"
		<< setw(10) << "First Name" << "|"
		<< setw(10) << "Last Name" << "|"
		<< setw(10) << "Nickname" << endl;

	while (!tempQueue.empty()) {
		Contact contact = tempQueue.front();
		tempQueue.pop();

		cout << setw(10) << index << "|"
			<< setw(10) << formatString(contact.getFirstName()) << "|"
			<< setw(10) << formatString(contact.getLastName()) << "|"
			<< setw(10) << formatString(contact.getNickname()) << "|" << endl;

		index++;
	}
}

// ����ó ���� ���� ǥ��
void PhoneBook::displayContactsDetails(int index) const {
	if (contacts.empty()) {
		cout << "����� ����ó�� �����ϴ�." << endl;
		return;
	}

	if (index < 0 || index >= contacts.size()) {
		cout << "��ȿ���� ���� �ε����Դϴ�." << endl;
		return;
	}

	std::queue<Contact> tempQueue = contacts;  // ť ���纻�� ����� Ư�� �ε��� ã��
	for (int i = 0; i < index; i++) {
		tempQueue.pop();
	}

	const Contact& contact = tempQueue.front();
	cout << "First Name: " << contact.getFirstName() << endl;
	cout << "Last Name: " << contact.getLastName() << endl;
	cout << "Nickname: " << contact.getNickname() << endl;
	cout << "Phone Number: " << contact.getPhoneNumber() << endl;
	cout << "Memo: " << contact.getMemo() << endl;
}