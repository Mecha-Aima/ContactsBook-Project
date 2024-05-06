#include <iostream>
#include "sort_search.h"
#include "HistoryObject.h"
#include "Contact.h"
#include "List.h"

int main()
{
    List<HistoryObject> frequentSearch(5);
    List<HistoryObject> history;
    // Create some contacts
    Contact c1("Ali", "Ahmed", "03001234567", "ali.a@gmail.com", new Address("House 1", "Street 1", "City 1", "Country 1"));
    Contact c2("Arslan", "Mohid", "03001234568", "arslan.m@yahoo.com", new Address("House 2", "Street 2", "City 2", "Country 2"));
    Contact c3("Babar", "Mian", "03001234569", "bilal.a@gmail.com", new Address("House 3", "Street 3", "City 3", "Country 3"));
    Contact c4("Shahid", "Khan", "03001234570", "shahid.k@outlook.com", new Address("House 4", "Street 4", "City 4", "Country 4"));
    Contact c5("Zeeshan", "Rauf", "03001234567", "zeeshan.r@gmail.com", new Address("House 5", "Street 5", "City 5", "Country 5"));

    // Create some history objects
    history.append(HistoryObject(13, 24, 30, 24, 12, 2023, c1));
    history.append(HistoryObject(23, 24, 30, 24, 12, 2022, c2));
    history.append(HistoryObject(14, 24, 30, 26, 8, 2004, c3));
    history.append(HistoryObject(14, 35, 30, 26, 8, 2003, c4));
    history.append(HistoryObject(5, 24, 45, 30, 10, 2010, c5));
    history.append(HistoryObject(10, 22, 0, 28, 7, 2006, c2));
    history.append(HistoryObject(10, 22, 0, 28, 7, 2005, c3));
    history.append(HistoryObject(22, 30, 0, 28, 7, 2005, c1));

    history[0].get_contact().set_search_count(5);
    history[1].get_contact().set_search_count(10);
    history[2].get_contact().set_search_count(2);
    history[3].get_contact().set_search_count(15);
    history[4].get_contact().set_search_count(7);
    history[5].get_contact().set_search_count(3);
    history[6].get_contact().set_search_count(8);
    history[7].get_contact().set_search_count(12);

    // Print the history objects
    std::cout << "Before sorting: " << std::endl;
    for (int i = 0; i < history.size(); i++)
    {
        std::cout << history[i] << "Search count: " << history[i].get_contact().get_search_count() << std::endl;
        std::cout << std::endl;
    }
    HistoryObject temp;
    sort_list(history, &temp, HistoryObject::by_search_count);
    std::cout << "----------------------------------------------\n";
    std::cout << "After sorting: " << std::endl;
    for (int i = 0; i < history.size(); i++)
    {
        std::cout << history[i] << "Search count: " << history[i].get_contact().get_search_count() << std::endl;
        std::cout << std::endl;
    }
}