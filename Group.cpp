#include "Group.h"

// Constructor
Group::Group(std::string n, int max) : name(n), max_contacts(max), no_of_contacts(0) {}
// Copy constructor
Group::Group(const Group& other) : name(other.name), max_contacts(other.max_contacts), no_of_contacts(other.no_of_contacts) {
    this->members = other.members;
}
// Assignment operator
Group& Group::operator=(const Group& other) {
    if (this == &other)
        return *this;
    name = other.name;
    no_of_contacts = other.no_of_contacts;
    max_contacts = other.max_contacts;
    members = other.members;
    return *this;
}

// Destructor
Group::~Group() {}

// Method to add a contact to the group
void Group::add_contact(int contact_ID)
{
    if (no_of_contacts == max_contacts)
    {
        return; // Max limit reached
    }
    members.append(contact_ID);
    
}

// Method to remove a contact from the group
void Group::remove_contact(int contact_ID)
{
    members.remove(contact_ID);
}


