#pragma once
#pragma once
#ifndef ADVANCESEARCH_H
#define ADVANCESEARCH_H
#include "HistoryObject.h"
#include "ContactsBook.h"
#include "Contact.h"
#include <string.h>
#include <cstring>
#include "List.h"

class AdvanceSearch {
private:
    int maxSize;
    List<Contact> searchResults;
    int item_count;
public:
    // Constructor
    AdvanceSearch();
    //Destructor
    ~AdvanceSearch();
    // Method to perform the search
    void perform_search(std::string query,ContactsBook& book);
    
    void display_results();
};
#endif // ADVANCESEARCH_H
