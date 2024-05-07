#include <iostream>
#include "sort.h"
#include "HistoryObject.h"
#include "AdvancedSearch.h"
#include "Contact.h"
#include "List.h"

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
    std::cout << "Added contacts." << std::endl;
    book.print_contacts();
    std::cout << "------------------------------------\n";

    // Create some history objects
    HistoryObject h1(13, 24, 30, 24, 12, 2023, c1);
    HistoryObject h2(23, 24, 30, 24, 12, 2022, c2);
    HistoryObject h3(14, 24, 30, 26, 8, 2004, c3);
    HistoryObject h4(14, 35, 30, 26, 8, 2003, c4);
    HistoryObject h5(5, 24, 45, 30, 10, 2010, c5);
    HistoryObject h6(10, 22, 0, 28, 7, 2006, c2);
    HistoryObject h7(10, 22, 0, 28, 7, 2005, c3);
    HistoryObject h8(22, 30, 0, 28, 7, 2005, c1);

    // Set random search counts
    h1.get_contact().set_search_count(5);
    h2.get_contact().set_search_count(3);
    h3.get_contact().set_search_count(2);
    h4.get_contact().set_search_count(7);
    h5.get_contact().set_search_count(4);
    h6.get_contact().set_search_count(10);
    h7.get_contact().set_search_count(1);
    h8.get_contact().set_search_count(6);

    SearchHistory sh;
    sh.add_search_item(h1);
    sh.add_search_item(h2);
    sh.add_search_item(h3);
    sh.add_search_item(h4);
    sh.add_search_item(h5);
    sh.add_search_item(h6); 
    sh.add_search_item(h7);
    sh.add_search_item(h8);
    std::cout << "Added search items." << std::endl;

    AdvanceSearch as;
    as.perform_search("zEeShAn.r@GmAiL.cOm", book);

    // Test get_results
    List<Contact> temp = as.get_results();
    std::cout << "------------------------------------\n";
    std::cout << "Search results: " << std::endl;
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << std::endl;
        std::cout << std::endl;
    }

    // Test get_search_history
    List<HistoryObject> temp = sh.get_search_history();
    std::cout << "------------------------------------\n";
    std::cout << "Search history: " << std::endl;
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << std::endl;
    }

    // Test get_searched_contacts
    List<Contact> temp2 = sh.get_searched_contacts();
    std::cout << "------------------------------------\n";
    std::cout << "Searched contacts: " << std::endl;
    for (int i = 0; i < temp2.size(); i++)
    {
        std::cout << temp2[i] << std::endl;
        std::cout << std::endl;
    }

    // Test get_top5
    List<HistoryObject> temp3 = sh.get_top5();
    std::cout << "------------------------------------\n";
    std::cout << "Top 5 frequent searches: " << std::endl;
    for (int i = 0; i < temp3.size(); i++)
    {
        std::cout << temp3[i] << std::endl;
    }

    // Test save_history
    sh.save_history("history.txt");
    // Test save_top5
    sh.save_top5("top5.txt");

    

    return 0;
    
}