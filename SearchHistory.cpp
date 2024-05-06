#include "SearchHistory.h"

SearchHistory::SearchHistory()
{
    frequentSearch = 0;
    history = 0;
    searchedContacts = 0;
    top5[5] = nullptr;
}

bool SearchHistory::check_frequent_search()
{
    // If the top5Size is less than 5, the new contact should always be added
    if (top5Size < 5) {
        return true;
    }
    int minIndex = 0;
    for (size_t i; i < top5Size; i++) {
        if (top5[i].get_search_count() < top5[minIndex].get_search_count()) {
            minIndex = i;
        }
    }
    // Check if the new contact has a higher search count than the contact with the lowest search count
    if (top5[minIndex].get_search_count() < contact.get_search_count()) {
        // Remove the contact with the lowest search count
        for (size_t i = minIndex; i < top5Size - 1; i++) {
            top5[i] = top5[i + 1];
        }
        // Add the new contact to the top5 array
        top5[top5Size - 1] = HistoryObject(contact);
        top5Size++;
        return true;
    }
    return false;
}

void SearchHistory::update_frequent_search(Contact& contact)
{
    for (size_t i = 0; i < top5size; i++) {
        if (top5[i].get_contact() == contact.get_contact()) {
            top5[i].add_search_count(); //It will increment the search count
            return;
        }
    }
    if (top5Size == 5) {
        // Find the contact with the lowest search count
        int minIndex = 0;
        for (size_t i; i < top5Size; i++) {
            if (top5[i].get_search_count() < top5[minIndex].get_search_count()) {
                minIndex = i;
            }
        }
        top5[minIndex] = HistoryObject(contact);
    }
    else {
        // If the array is not full, simply add the new contact
        top5[top5Size] = HistoryObject(contact);
        top5Size++;
    }
}

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



