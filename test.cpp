#include "ContactsBook.h"

int main()
{
    int size;
    std::cout << "Enter the size of the contacts book: ";
    std::cin >> size;
    ContactsBook book(size);
    Address *ad1 = new Address("House 1", "Street 1", "City 1", "Country 1");
    Contact c1("Ali", "Ahmed", "03331234567", "ali.ahmed@gmail.com", ad1);
    Address *ad2 = new Address("House 2", "Street 2", "City 2", "Country 2");
    Contact c2("Aimen", "Malik", "03331234568", "aimen.malik@gmail.com", ad2);
    Address *ad3 = new Address("House 3", "Street 3", "City 3", "Country 3");
    Contact c3("Ali", "Ahmed", "03331234567", "ali.ahmed@gmail.com", ad1);
    Contact c4("Amal", "Malik", "94054356561", "amal@yahoo.com", ad3);
    // Add contacts to the book
    book.add_contact(c1);
    book.add_contact(c2);
    book.add_contact(c3);
    book.add_contact(c4);
    // Add some more contacts after reading from file
    book.load_from_file("contacts.txt");
    // Print total contacts
    std::cout << "Total contacts: " << book.total_contacts() << std::endl;
    // Print all contacts
    std::cout << "\nAll contacts: " << std::endl;
    book.print_contacts();
    // Search for a contact by name
    std::cout << "\nSearch for a contact by name" << std::endl;
    Contact *found = book.search_contact("Ali", "Ahmed");
    if (found != nullptr)
    {
        std::cout << "Contact found: " << std::endl;
        found->print_contact();
    }
    else
    {
        std::cout << "Contact not found" << std::endl;
    }
    // Search for a contact by mobile number
    std::cout << "\nSearch for a contact by mobile number" << std::endl;
    found = book.search_contact("94054356561");
    if (found != nullptr)
    {
        std::cout << "Contact found: " << std::endl;
        found->print_contact();
    }
    else
    {
        std::cout << "Contact not found" << std::endl;
    }
    // Search for a contact by address
    std::cout << "\nSearch for a contact by address" << std::endl;
    found = book.search_contact(*ad3);
    if (found != nullptr)
    {
        std::cout << "Contact found: " << std::endl;
        found->print_contact();
    }
    else
    {
        std::cout << "Contact not found" << std::endl;
    }
    // Merge duplicates
    std::cout << "Merging duplicates..." << std::endl;
    book.merge_duplicates();

    // Print total contacts
    std::cout << "\nTotal contacts: " << book.total_contacts() << std::endl;
    // Print contacts sorted by first name
    std::cout << "\nContacts sorted by first name" << std::endl;
    book.print_contacts_sorted("first_name");
    // Print contacts sorted by last name
    std::cout << "\nContacts sorted by last name" << std::endl;
    book.print_contacts_sorted("last_name");
    // Save contact book to a file
    std::cout << "\nSaving contacts to a file..." << std::endl;
    book.save_to_file("contacts2.txt");

    delete ad1;
    delete ad2;
    delete ad3;
    
    return 0;
}