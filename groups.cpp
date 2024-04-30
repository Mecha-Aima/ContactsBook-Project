#include "Groups.h"
// Constructor
Groups::Groups() {
    name = ""; // Initialize name to an empty string
    numberOfContacts = 0; // Initialize number of contacts to 0
}
// Method to add a contact to the group
void Groups::addContact(int contactId) {
    if (numberOfContacts < max_Contacts) { // Check if there's space to add a contact
        contactIDs[numberOfContacts] = contactId; // Add contact ID to the array
        numberOfContacts++; // Increment the number of contacts
        cout << "Contact added to group successfully." << endl;
    }
    else {
        cout << "Cannot add more contacts. Group is full." << endl;
    }
}
// Method to remove a contact from the group
void Groups::removeContact(int contactID) {
    int index = -1; // Initialize index to -1, indicating contact not found
    for (int i = 0; i < numberOfContacts; i++) 
    {
        if (contactIDs[i] == contactID) 
        {
            index = i; // Set index to the position of the contact ID in the array
            break;
        }
    }
    if (index != -1)
    { // If contact found
        // Shift remaining elements to the left to remove the contact
        for (int i = index; i < numberOfContacts - 1; i++)
        {
            contactIDs[i] = contactIDs[i + 1];
        }
        numberOfContacts--; // Decrement the number of contacts
        cout << "Contact removed from group successfully." << endl;
    }
    else {
        cout << "Contact not found in group." << endl;
    }
}
// Method to get the name of the group
string Groups::getName() {
    return name;
}
// Method to get the number of contacts in the group
int Groups::getNumberOfContacts() {
    return numberOfContacts;
}
// Method to get the list of contact IDs in the group
int* Groups::getContactIDs() {
    return contactIDs;
}