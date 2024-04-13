#include "Address.h"

// Constructors
Address::Address() {
	house = "";
	street = "";
	city  = "";
	country = "";
}

Address::Address(std::string house, std::string street, std::string city, std::string country) {
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}

// Getters
std::string Address::get_house() const { return house; }
std::string Address::get_street() const { return street; }
std::string Address::get_city() const { return city; }
std::string Address::get_country() const { return country; }

// Setters
void Address::set_house(std::string house){
	this->house = house;
}
void Address::set_street(std::string street){
	this->street = street;
}
void Address::set_city(std::string city){
	this->city = city;
}
void Address::set_country(std::string country){
	this->country = country;
}


bool Address::equals(const Address& address)
{
	if (this == &address) {
		return true;
	}
	if (this->house != address.house ||
		this->street != address.street ||
		this->city != address.city ||
		this->country != address.country)
	{
		return false;
	}
	return true;
}

void Address::print_address()
{
	std::cout << house << ", " << street << ", " << city << ", " << country << std::endl;
}

Address Address::copy_address()
{
	// Return a copy of current object
	return Address(house, street, city, country);
}
