#include "AdvanceSearch.h"
#include "HistoryObject.h"
// Constructor
AdvanceSearch::AdvanceSearch(int maxSize) :
    history(nullptr), searchResults(nullptr), item_count(0), max_size(maxSize) {
    //history = new HistoryObject[maxSize]; //getting error on this line
    searchResults = new Contact[maxSize];
    for (int i = 0; i < 5; i++) {
        frequently_searched[i].get_first_name() = "";
        frequently_searched[i].get_last_name() = "";
    }
}
// Destructor
AdvanceSearch::~AdvanceSearch() {
    // Deallocate memory for history array
    delete[] history;
    // Deallocate memory for searchResults array
    delete[] searchResults;
}
// Method to perform the search
void AdvanceSearch::perform_search() {
    // Implement the search logic here
}
// Method to update frequently searched contacts
void AdvanceSearch::update_frequently_searched(const Contact& contact) {
    bool found = false;
    // Iterate through frequently_searched array
    for (int i = 0; i < 5; i++) {
        if (frequently_searched[i].get_first_name() == contact.get_first_name() &&
            frequently_searched[i].get_last_name() == contact.get_last_name()) {
            found = true;
            break;
        }
    }
    // If the contact is not found, add it to the frequently_searched array
    if (!found) {
        for (int i = 4; i > 0; i--) {
            frequently_searched[i] = frequently_searched[i - 1];
        }
        frequently_searched[0] = contact;
    }
}
// Getter for frequently searched contacts
const Contact* AdvanceSearch::get_frequently_searched() const {
    // Reserve memory for a new array with a size of 5
    const Contact* frequently_searched_array = new Contact[5];
    // Copy the contents of frequently_searched to frequently_searched_array
    for (int i = 0; i < 5; i++) {
        frequently_searched_array[i].get_first_name() = frequently_searched[i].get_first_name();
        frequently_searched_array[i].get_last_name() = frequently_searched[i].get_last_name();
        frequently_searched_array[i].get_mobile_number() = frequently_searched[i].get_mobile_number();
        frequently_searched_array[i].get_email_address() = frequently_searched[i].get_email_address();
    }
    return frequently_searched_array;
}

// Method to add a search result
void AdvanceSearch::add_search_result(const Contact& result) {
    if (item_count < max_size) {
        searchResults[item_count++] = result;
    }
    else {
        // Handle the case where searchResults array is full
        // For example, you can overwrite the oldest result
        if (item_count >= max_size) {
            for (int i = 1; i < max_size; i++) {
                searchResults[i - 1] = searchResults[i];
            }
            searchResults[max_size - 1] = result;
        }
    }
    // Update frequently searched contacts
    update_frequently_searched(result);
}
// Getter for search results
const Contact* AdvanceSearch::get_search_results() const {
    // Reserve memory for a new array with the same size as searchResults
    const Contact* search_results_array = new Contact[item_count];
    // Copy the contents of searchResults to search_results_array
    for (int i = 0; i < item_count; i++) {
        search_results_array[i].get_first_name() = searchResults[i].get_first_name();
        search_results_array[i].get_last_name() = searchResults[i].get_last_name();
        search_results_array[i].get_mobile_number() = searchResults[i].get_mobile_number();
        search_results_array[i].get_email_address() = searchResults[i].get_email_address();
    }
    return search_results_array;
}
