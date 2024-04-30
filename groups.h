#pragma once
#ifndef BASIC_LIB
#define BASIC_LIB
#include "contactsBook.h"
#include <iostream>
#include <string>
#define max_Contacts 100
using namespace std;
class Groups {
private:
	string	name;
	int contactIDs[max_Contacts];
	int numberOfContacts;
public:
	Groups();
	void addContact(int contactId);
	void removeContact(int contactID);
    // Method to get the name of the group
	string getName();
    // Method to get the number of contacts in the group
	int getNumberOfContacts();
    // Method to get the list of contact IDs in the group
	int* getContactIDs();
};
#endif