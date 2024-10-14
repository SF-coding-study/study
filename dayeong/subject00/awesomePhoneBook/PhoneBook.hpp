#pragma once
#include <iostream>
#include <queue>

#include "Contact.hpp"

using namespace std;

class PhoneBook
{
private:
	queue<Contact> contacts; //연락처를 저장하는 큐
	size_t maxSize; //큐의 최대 크기(8)

public:
	PhoneBook(size_t maxSize = 8); //생성자에서 최대 크기 설정
	void addContact(const Contact& newContact);		// 연락처 추가
	void displayContacts() const;					//저장된 연락처 목록 표시
	void displayContactsDetails(int index) const;	//특정 연락처의 세부 사항 표시
};