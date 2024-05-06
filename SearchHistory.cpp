#include "SearchHistory.h"

void SearchHistory::add_search_item(Contact& contact, HistoryObject& historyObject) {
    // Assuming history is an array of HistoryObject instances
    if (historySize < 100) {
        history[historySize] = historyObject;
        searchedContacts[historySize++] = contact;
    }
    else {
        throw ("Cannot add more.");
    }
}

List<HistoryObject> SearchHistory::get_search_history() {
    // reverse search history to show latest first
    List<HistoryObject> temp;
    for (int i = historySize - 1; i >= 0; i--) {
        temp.append(history[historySize - i - 1]);
    }
    return temp;
}

List<Contact> SearchHistory::get_searched_contacts() {
    // reverse searched contacts to show latest first
    List<Contact> temp;
    for (int i = historySize - 1; i >= 0; i--) {
        temp.append(searchedContacts[historySize - i - 1]);
    }
    return temp;
}



