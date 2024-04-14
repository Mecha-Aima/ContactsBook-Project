#include "ContactsBook.h"
#include <iomanip>
using namespace std;

void print_menu();
ContactsBook create_list();
void add_contact(ContactsBook& contacts_book);
void merge_duplicates(ContactsBook& contacts_book);
void store_to_file(ContactsBook& contacts_book);
void load_from_file(ContactsBook& contacts_book);

int main()
{
    ContactsBook contacts_book(4);
    int choice;
    do
    {
        print_menu();
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            contacts_book = create_list();
        } else if (choice == 2) {
            add_contact(contacts_book);
        } else if (choice == 3) {
            merge_duplicates(contacts_book);
        } else if (choice == 4) {
            store_to_file(contacts_book);
        } else if (choice == 5) {
            load_from_file(contacts_book);
        } else if (choice == 0) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);
    
    return 0;
}

ContactsBook create_list()
{
    cout << "Enter the number of contacts: ";
    int list_size;
    cin >> list_size;
    ContactsBook contacts_book(list_size);
    return contacts_book;
}

void print_menu()
{
    cout << "1. Create a contacts list" << endl;
    cout << "2. Add New Contact" << endl;
    cout << "3. Merge Duplicates" << endl;
    cout << "4. Store To File" << endl;
    cout << "5. Load From File" << endl;
    cout << "6. Print Contacts Sorted" << endl;
    cout << "7. Print Contacts" << endl;
    cout << "8. Search contacts" << endl;
    cout << "9. Display Count of Contacts" << endl;
    cout << "0. Exit" << endl;
}

void add_contact(ContactsBook& contacts_book)
{
    Contact contact;
    cin >> contact;
    contacts_book.add_contact(contact);
}

void merge_duplicates(ContactsBook& contacts_book)
{
    contacts_book.merge_duplicates();
}

void store_to_file(ContactsBook& contacts_book) {
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;
    contacts_book.save_to_file(file_name);
}

void load_from_file(ContactsBook& contacts_book)
{
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;
    contacts_book.load_from_file(file_name);
}
