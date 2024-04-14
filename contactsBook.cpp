#include "ContactsBook.h"
#include <iostream>
#include <fstream>
ContactsBook::ContactsBook(int size_of_list) {
    size_of_contacts = size_of_list;
    contacts_count = 0;
    contacts_list = new Contact[size_of_list];
}
ContactsBook::~ContactsBook() {
    delete[] contacts_list;
}
int ContactsBook::add_contact(const Contact& contact) {
    if (full()) {
        resize_list();
    }
    contacts_list[contacts_count] = contact;
    contacts_count++;
    return 1;
}
int ContactsBook::total_contacts() {
    return contacts_count;
}
bool ContactsBook::full() {
    return contacts_count == size_of_contacts;
}
void ContactsBook::resize_list() {
    int new_size = size_of_contacts * 2;
    Contact* temp_contacts_list = new Contact[new_size];
    for (int i = 0; i < contacts_count; ++i) {
        temp_contacts_list[i] = *(contacts_list[i].copy_contact());
    }
    delete[] contacts_list;
    contacts_list = temp_contacts_list;
    size_of_contacts = new_size;
}
Contact* ContactsBook::search_contact(string first_name, string last_name) {
    for (int i = 0; i < contacts_count; ++i) {
        if (contacts_list[i].get_first_name() == first_name &&
            contacts_list[i].get_last_name() == last_name) {
            return contacts_list[i].copy_contact();
        }
    }
    return nullptr;
}
Contact* ContactsBook::search_contact(string phone) {
    for (int i = 0; i < contacts_count; ++i) {
        if (contacts_list[i].get_mobile_number() == phone) {
            return contacts_list[i].copy_contact();
        }
    }
    return nullptr;
}
Contact* ContactsBook::search_contact(const Address& address) {
    for (int i = 0; i < contacts_count; ++i) {
        if (contacts_list[i].get_address().equals(address)) {
            return contacts_list[i].copy_contact();
        }
    }
    return nullptr;
}
void ContactsBook::print_contacts_sorted(string choice) {

}
bool compare_contacts(Contact& contact1,Contact& contact2, string choice) {
    if (choice == "first_name") {
        return contact1.get_first_name() < contact2.get_first_name();
    }
    else if (choice == "last_name") {
        return contact1.get_last_name() < contact2.get_last_name();
    }
    else {
        return contact1.get_first_name() < contact2.get_first_name();
    }
}
void ContactsBook::sort_contacts_list(Contact* contacts_list, string choice) {
    for (int i = 0; i < contacts_count - 1; ++i) {
        for (int j = 0; j < contacts_count - i - 1; ++j) {
            if (compare_contacts(contacts_list[j], contacts_list[j + 1], choice)) {
                Contact temp = contacts_list[j];
                contacts_list[j] = contacts_list[j + 1];
                contacts_list[j + 1] = temp;
            }
        }
    }
}
void ContactsBook::merge_duplicates() {

}
void ContactsBook::load_from_file(string file_name) {

}
void ContactsBook::save_to_file(string file_name) {
 
}