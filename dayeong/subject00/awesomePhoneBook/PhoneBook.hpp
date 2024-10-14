#pragma once
#include <iostream>
#include <queue>

#include "Contact.hpp"

using namespace std;

class PhoneBook
{
private:
	queue<Contact> contacts; //����ó�� �����ϴ� ť
	size_t maxSize; //ť�� �ִ� ũ��(8)

public:
	PhoneBook(size_t maxSize = 8); //�����ڿ��� �ִ� ũ�� ����
	void addContact(const Contact& newContact);		// ����ó �߰�
	void displayContacts() const;					//����� ����ó ��� ǥ��
	void displayContactsDetails(int index) const;	//Ư�� ����ó�� ���� ���� ǥ��
};