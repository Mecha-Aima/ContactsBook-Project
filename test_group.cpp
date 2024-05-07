#include "ContactsBook.h"
#include "Group.h"
#include "Contact.h"
#include "List.h"
#include "sort.h"

int main()
{
    ContactsBook book(10);
    Contact c1("Ali", "Ahmed", "03001234567", "ali.a@gmail.com", new Address("House 1", "Street 1", "City 1", "Country 1"));
    Contact c2("Arslan", "Mohid", "03001234568", "arslan.m@yahoo.com", new Address("House 2", "Street 2", "City 2", "Country 2"));
    Contact c3("Babar", "Aslam", "03001234569", "babr.a@gmail.com", new Address("House 3", "Street 3", "City 3", "Country 3"));
    Contact c4("Shahid", "Khan", "03001234570", "shahid.k@outlook.com", new Address("House 4", "Street 4", "City 4", "Country 4"));
    Contact c5("Zeeshan", "Rauf", "03001234567", "zeeshan.r@gmail.com", new Address("House 5", "Street 5", "City 5", "Country 5"));
    std::cout << "------------------------------------\n";
    book.add_contact(c1);
    book.add_contact(c2);
    book.add_contact(c3);
    book.add_contact(c4);
    book.add_contact(c5);
    book.load_from_file("read_contacts.txt");
    std::cout << "Added contacts." << std::endl;

    // Create two groups
    Group g1("Friends", 5);
    Group g2("Family", 5);
    Group g3("Colleagues", 5);
    Group g4("Grandparents", 5);
    Group g5("Cousins", 5);
    Group g6("Siblings", 5);
    Group g7("Uncles", 5);
    Group g8("Team Project", 5);
    g1.add_contact(0, book);
    g1.add_contact(1, book);
    g1.add_contact(2, book);
    g1.add_contact(3, book);
    g1.add_contact(4, book);
    g2.add_contact(5, book);
    g2.add_contact(6, book);
    g2.add_contact(1, book);

    List<std::string> temp = c1.get_groups();
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << std::endl;
    }

    // Display groups of contact with id 1
    List<std::string> contact1_groups = book[1].get_groups();
    for (int i = 0; i < contact1_groups.size(); i++)
    {
        std::cout << contact1_groups[i] << std::endl;
    }

    std::cout << "------------------------------------\n";
    // Display groups of contact with id 5
    List<std::string> contact5_groups = book[5].get_groups();
    for (int i = 0; i < contact5_groups.size(); i++)
    {
        std::cout << contact5_groups[i] << std::endl;
    }

    // Display members of group 1
    std::cout << "------------------------------------\n";
    List<int> group1 = g1.get_members(); 
    for (int i = 0; i < group1.size(); i++)
    {
        std::cout << book.get_contact(group1[i]) << std::endl;
    }

    // Sort groups by their names
    List<Group> groups;
    groups.append(g1);
    groups.append(g2);
    groups.append(g3);
    groups.append(g4);
    groups.append(g5);
    groups.append(g6);
    groups.append(g7);
    groups.append(g8);
    sort_list(groups, &groups[0], Group::less_than);
    std::cout << "------------------------------------\n";
    std::cout << "Sorted groups: " << std::endl;
    for (int i = 0; i < groups.size(); i++)
    {
        std::cout << groups[i].get_name() << std::endl;
    }

    return 0;
}

