// Use this file to test your code
#include "ContactsBook.h"
#include "Group.h"
#include "List.h"
#include "HistoryObject.h"
#include <iostream>

// Testing Contact class sorting
int main()
{
    ContactsBook book(10);
    Contact c1("Ali", "Ahmed", "03001234567", "ali.a@gmail.com", new Address("House 1", "Street 1", "City 1", "Country 1"));
    Contact c2("Arslan", "Mohid", "03001234568", "arslan.m@yahoo.com", new Address("House 2", "Street 2", "City 2", "Country 2"));
    Contact c3("Babar", "Mian", "03001234569", "bilal.a@gmail.com", new Address("House 3", "Street 3", "City 3", "Country 3"));
    Contact c4("Shahid", "Khan", "03001234570", "shahid.k@outlook.com", new Address("House 4", "Street 4", "City 4", "Country 4"));
    Contact c5("Zeeshan", "Rauf", "03001234567", "zeeshan.r@gmail.com", new Address("House 5", "Street 5", "City 5", "Country 5"));
    book.load_from_file("read_contacts.txt");
    std::cout << "------------------------------------\n";
    book.add_contact(c1);
    book.add_contact(c2);
    book.add_contact(c3);
    book.add_contact(c4);
    book.add_contact(c5);
    std::cout << "Printing contacts in the order they were added" << std::endl;
    book.print_contacts();
    std::cout << "----------------------------------------\n";
    std::cout << "Printing contacts sorted by first name in ascending order" << std::endl;
    book.sort_contacts("first_name", 0);
    book.print_contacts();
    std::cout << "----------------------------------------\n";
    std::cout << "Printing contacts sorted by last name in descending order" << std::endl;
    book.sort_contacts("last_name", 1);
    book.print_contacts();
    std::cout << "----------------------------------------\n";
    std::cout << "Printing contacts sorted by first name in descending order" << std::endl;
    book.sort_contacts("first_name", 1);
    book.print_contacts();
    std::cout << "----------------------------------------\n";
    std::cout << "Printing contacts sorted by last name in ascending order" << std::endl;
    book.sort_contacts("last_name", 0);
    book.print_contacts();
    std::cout << "----------------------------------------\n";

    return 0;
}

// TESTING HISTORYOBJECT CLASS SORTING
// void sort_list(List<HistoryObject>& list, std::string choice, int order)
// {
//     // choice == "date or time"
//     // order == 0 for ascending, 1 for descending
//     if(choice == "date")
//     {
//         if(order==0)
            
//     }
// }
// int main()
// {
//     List<HistoryObject> history;
//     // Append random history objects to the list
//     history.append(HistoryObject(13, 24, 30, 24, 12, 2023));
//     history.append(HistoryObject(23, 24, 30, 24, 12, 2022));
//     history.append(HistoryObject(14, 24, 30, 26, 8, 2004));
//     history.append(HistoryObject(14, 35, 30, 26, 8, 2003));
//     history.append(HistoryObject(5, 24, 45, 30, 10, 2010));
//     history.append(HistoryObject(10, 22, 0, 28, 7, 2006));
//     history.append(HistoryObject(10, 22, 0, 28, 7, 2005));
//     history.append(HistoryObject(22, 30, 0, 28, 7, 2005));
    

//     return 0;
// }