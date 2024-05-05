#pragma once
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB
#include "Address.h"
class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;
public:
	bool equals(Contact contact);
	Contact* copy_contact();
	void print_contact();
	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
	// Setters
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_mobile_number(std::string mobile_number);
	void set_email_address(std::string email_address);
	void set_address(Address* address);
	// Getters
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_mobile_number() const;
	std::string get_email_address() const;
	Address* get_address() const;
	// Overload cin for Contact
	friend std::istream& operator>>(std::istream& in, Contact& contact);
	// Overload cout for Contact
	friend std::ostream& operator<<(std::ostream& out, const Contact& contact);
	// Overload comparison operator for Contact
	bool operator==(const Contact& other);
};
