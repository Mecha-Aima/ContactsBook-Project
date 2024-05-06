#ifndef SEARCHHISTORY_H
#define SEARCHHISTORY_H
#include <string>
#include "Contact.h"
#include "HistoryObject.h"
#include "List.h"
using namespace std;
class SearchHistory {
private:
    List<HistoryObject> frequentSearch;
    List<HistoryObject> history;
    List<Contact> searchedContacts;
    int historySize = 0; // Track current size of history
    int top5Size = 0; // Track current size of top5
public:
    SearchHistory(); // Constructor to initialize the lists
    bool check_frequent_search(Contact& contact);
    void update_frequent_search(HistoryObject& h);
    void add_search_item(HistoryObject& historyObject);
    List<HistoryObject> get_search_history();
    List<Contact> get_searched_contacts();
    //void save_to_file(string historyFile, string top5File);
};
#endif

// Algorithm:
// 1. 