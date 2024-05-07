#pragma once
#pragma once
#ifndef ADVANCESEARCH_H
#define ADVANCESEARCH_H
#include "HistoryObject.h"
<<<<<<< HEAD
#include "SearchHistory.h"
#include "ContactsBook.h"
#include "Contact.h"
#include "List.h"
#include <string>

=======
#include "ContactsBook.h"
#include "Contact.h"
#include <string.h>
#include <cstring>
#include "List.h"
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2

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
<<<<<<< HEAD
    List<string> get_results();
    void update_history(HistoryObject &h, SearchHistory &sh);
};
#endif // ADVANCESEARCH_H
=======
    
    void display_results();
};
#endif // ADVANCESEARCH_H
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2
