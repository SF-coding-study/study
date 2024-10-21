#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

using namespace std;

PhoneBook::PhoneBook(size_t maxSize) : maxSize(maxSize) {}

// 연락처 추가
void PhoneBook::addContact(const Contact& newContact) {
	if (contacts.size() >= maxSize) {
		cout << "전화번호부가 가득 찼습니다.가장 오래된 연락처가 삭제됩니다." << endl;
		contacts.pop();
	}
	contacts.push(newContact);
	cout << "새로운 연락처가 추가되었습니다." << endl;
}

// 출력 문자열 형식
string formatString(const string& str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

// 연락처 목록 표시
void PhoneBook::displayContacts() const {
	if (contacts.empty()) {
		cout << "저장된 연락처가 없습니다." << endl;
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

// 연락처 세부 정보 표시
void PhoneBook::displayContactsDetails(int index) const {
	if (contacts.empty()) {
		cout << "저장된 연락처가 없습니다." << endl;
		return;
	}

	if (index < 0 || index >= contacts.size()) {
		cout << "유효하지 않은 인덱스입니다." << endl;
		return;
	}

	std::queue<Contact> tempQueue = contacts;  // 큐 복사본을 사용해 특정 인덱스 찾기
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