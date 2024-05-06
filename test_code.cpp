// Use this file to test your code
#include "List.h"
#include "sort_search.h"
#include "HistoryObject.h"
#include <iostream>
#include "Group.h"

// int main()
// {
//     // Test Group class
//     Group g1("Group 1", 10);
//     Group g2("Group 2", 10);
//     Group g3("Group 3", 10);
//     Group g4("Group 4", 10);

//     // Create a contact Book
//     ContactsBook book(10);
//     Contact c1("Ali", "Ahmed", "03001234567", "ali.a@gmail.com", new Address("House 1", "Street 1", "City 1", "Country 1"));
//     Contact c2("Arslan", "Mohid", "03001234568", "arslan.m@yahoo.com", new Address("House 2", "Street 2", "City 2", "Country 2"));
//     Contact c3("Babar", "Mian", "03001234569", "bilal.a@gmail.com", new Address("House 3", "Street 3", "City 3", "Country 3"));
//     Contact c4("Shahid", "Khan", "03001234570", "shahid.k@outlook.com", new Address("House 4", "Street 4", "City 4", "Country 4"));
//     Contact c5("Zeeshan", "Rauf", "03001234567", "zeeshan.r@gmail.com", new Address("House 5", "Street 5", "City 5", "Country 5"));
//     std::cout << "------------------------------------\n";
//     book.add_contact(c1);
//     book.add_contact(c2);
//     book.add_contact(c3);
//     book.add_contact(c4);
//     book.add_contact(c5);
    
//     book.print_contacts();
//     std::cout << book.get_contacts()[0].get_contact_id() << std::endl;
//     std::cout << book.get_contacts()[1].get_contact_id() << std::endl;
//     std::cout << book.get_contacts()[2].get_contact_id() << std::endl;
//     std::cout << book.get_contacts()[3].get_contact_id() << std::endl;
//     std::cout << book.get_contacts()[4].get_contact_id() << std::endl;
//     std::cout << "------------------------------------\n";
    
//     // Print contact IDs of book contacts
//     List<int> contact_ids = book.get_member_IDs();
//     for (int i = 0; i < contact_ids.size(); i++)
//     {
//         std::cout << contact_ids[i] << std::endl;
//     }

//     // Add c1 to g1, g2, g3
//     g1.add_contact(c1.get_contact_id(), book);
//     g2.add_contact(c1.get_contact_id(), book);
//     g3.add_contact(c1.get_contact_id(), book);
//     g4.add_contact(c1.get_contact_id(), book);

//     // Add contacts to groups
//     // g1.add_contact(c1.get_contact_id(), book);
//     // g1.add_contact(c2.get_contact_id(), book);
//     // g2.add_contact(c1.get_contact_id(), book);
//     // g2.add_contact(c3.get_contact_id(), book);

//     // Print groups of c1
//     std::cout << "------------------------------------\n";
//     // Get the groups of c1
//     List<std::string> groups = c1.get_groups();
//     std::cout << groups.size() << std::endl;
//     // Print each group name
//     for (int i = 0; i < groups.size(); i++)
//     {
//         std::cout << groups[i] << std::endl;
//     }
// }

// Testing Contact class sorting
// int main()
// {
//     ContactsBook book(10);
//     Contact c1("Ali", "Ahmed", "03001234567", "ali.a@gmail.com", new Address("House 1", "Street 1", "City 1", "Country 1"));
//     Contact c2("Arslan", "Mohid", "03001234568", "arslan.m@yahoo.com", new Address("House 2", "Street 2", "City 2", "Country 2"));
//     Contact c3("Babar", "Mian", "03001234569", "bilal.a@gmail.com", new Address("House 3", "Street 3", "City 3", "Country 3"));
//     Contact c4("Shahid", "Khan", "03001234570", "shahid.k@outlook.com", new Address("House 4", "Street 4", "City 4", "Country 4"));
//     Contact c5("Zeeshan", "Rauf", "03001234567", "zeeshan.r@gmail.com", new Address("House 5", "Street 5", "City 5", "Country 5"));
//     book.load_from_file("read_contacts.txt");
//     std::cout << "------------------------------------\n";
//     book.add_contact(c1);
//     book.add_contact(c2);
//     book.add_contact(c3);
//     book.add_contact(c4);
//     book.add_contact(c5);
//     std::cout << "Printing contacts in the order they were added" << std::endl;
//     book.print_contacts();
//     std::cout << "----------------------------------------\n";
//     std::cout << "PRINTING CONTACTS SORTED BY FIRST NAME IN ASCENDING ORDER" << std::endl;
//     sort_list(book.get_contacts(), book.total_contacts(), new Contact(), Contact::fn_less_than);
//     book.print_contacts();
//     std::cout << "----------------------------------------\n";
//     std::cout << "PRINTING CONTACTS SORTED BY FIRST NAME IN DESCENDING ORDER" << std::endl;
//     sort_list(book.get_contacts(), book.total_contacts(), new Contact(), Contact::fn_greater_than);
//     book.print_contacts();
//     std::cout << "----------------------------------------\n";
//     std::cout << "PRINTING CONTACTS SORTED BY LAST NAME IN ASCENDING ORDER" << std::endl;
//     sort_list(book.get_contacts(), book.total_contacts(), new Contact(), Contact::ln_less_than);
//     book.print_contacts();
//     std::cout << "----------------------------------------\n";
//     std::cout << "PRINTING CONTACTS SORTED BY LAST NAME IN DESCENDING ORDER" << std::endl;
//     sort_list(book.get_contacts(), book.total_contacts(), new Contact(), Contact::ln_greater_than);
//     book.print_contacts();
//     std::cout << "----------------------------------------\n";

//     return 0;
// }

// TESTING HISTORYOBJECT CLASS SORTING
int main()
{
    List<HistoryObject> history;
    Contact c1("Ali", "Ahmed", "03001234567", "ali.a@gmail.com", new Address("House 1", "Street 1", "City 1", "Country 1"));
    Contact c2("Arslan", "Mohid", "03001234568", "arslan.m@yahoo.com", new Address("House 2", "Street 2", "City 2", "Country 2"));
    Contact c3("Babar", "Mian", "03001234569", "bilal.a@gmail.com", new Address("House 3", "Street 3", "City 3", "Country 3"));
    Contact c4("Shahid", "Khan", "03001234570", "shahid.k@outlook.com", new Address("House 4", "Street 4", "City 4", "Country 4"));
    Contact c5("Zeeshan", "Rauf", "03001234567", "zeeshan.r@gmail.com", new Address("House 5", "Street 5", "City 5", "Country 5"));
    // Append random history objects to the list
    std::cout << "Before sorting: " << std::endl;
    history.append(HistoryObject(13, 24, 30, 24, 12, 2023, c1));
    history.append(HistoryObject(23, 24, 30, 24, 12, 2022, c2));
    history.append(HistoryObject(14, 24, 30, 26, 8, 2004, c3));
    history.append(HistoryObject(14, 35, 30, 26, 8, 2003, c4));
    history.append(HistoryObject(5, 24, 45, 30, 10, 2010, c5));
    history.append(HistoryObject(10, 22, 0, 28, 7, 2006, c2));
    history.append(HistoryObject(10, 22, 0, 28, 7, 2005, c3));
    history.append(HistoryObject(22, 30, 0, 28, 7, 2005, c1));
    for (int i = 0; i < history.size(); i++)
    {
        std::cout << history[i] << std::endl;
    }
    std::cout << "------------------------------------\n";
    sort_list(history.get_list(), history.size(), new HistoryObject(), HistoryObject::greater_than);
    std::cout << "\nAfter sorting: " << std::endl;
    for (int i = 0; i < history.size(); i++)
    {
        std::cout << history[i] << std::endl;
    }
    std::cout << "------------------------------------\n";

    // Get contacts stored in the history objects
    List<Contact> contacts;
    for (int i = 0; i < history.size(); i++)
    {
        contacts.append(history[i].get_contact());
    }
    std::cout << "Contacts in the history objects: " << std::endl;
    for (int i = 0; i < contacts.size(); i++)
    {
        std::cout << contacts[i] << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
