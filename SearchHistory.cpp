#include "SearchHistory.h"

SearchHistory::SearchHistory(): frequentSearch(5), history(100), searchedContacts(100) { }

bool SearchHistory::check_frequent_search(Contact& contact)
{
    // If the top5Size is less than 5, the new contact should always be added
    if (frequentSearch.size() < 5) {
        return true;
    }
    
    for(int i=0; i < frequentSearch.size(); i++)
    {
        // If the contact's search count is greater than the search count of any of the top 5 frequent searches
        if(frequentSearch[i].get_contact().get_search_count() < contact.get_search_count())
        {
            // Return true to indicate that the contact should be added to the top 5 frequent searches
            return true;
        }
    }
    return false;
}

void SearchHistory::update_frequent_search(HistoryObject& h)
{
    
}

void SearchHistory::add_search_item(HistoryObject& historyObject) {
    // Assuming history is an array of HistoryObject instances
    if (historySize < 100) {
        history[historySize] = historyObject;
        // Add the contact to the searchedContacts list
        searchedContacts[historySize++] = historyObject.get_contact();
        if(check_frequent_search(historyObject.get_contact()))
        {
            update_frequent_search(historyObject);
        }
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



