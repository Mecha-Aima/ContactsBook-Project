#ifndef ADVANCEDSEARCH_H
#define ADVANCEDSEARCH_H
#include "HistoryObject.h"
#include "SearchHistory.h"
#include "ContactsBook.h"
#include "List.h"
#include <string>

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
    List<string> get_results();
    void update_history(HistoryObject &h, SearchHistory &sh);
};
#endif // ADVANCEDSEARCH_H
    
    void display_results();
};
#endif // ADVANCESEARCH_H
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2
