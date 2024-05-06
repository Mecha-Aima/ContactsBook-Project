#pragma once
#ifndef ADVANCESEARCH_H
#define ADVANCESEARCH_H
#include "HistoryObject.h"
#include "Contact.h"
class AdvanceSearch {
private:
    HistoryObject* history;
    Contact* searchResults;
    Contact frequently_searched[5];
    int item_count;
    int max_size;
public:
    // Constructor
    AdvanceSearch(int maxSize);
    //Destructor
    ~AdvanceSearch();
    // Method to perform the search
    void perform_search();
    // Method to update frequently searched contacts
    void update_frequently_searched(const Contact& contact);
    // Getter for frequently searched contacts
    const Contact* get_frequently_searched() const;
    // Method to add a search result
    void add_search_result(const Contact& result);
    // Getter for search results
    const Contact* get_search_results() const;
};
#endif // ADVANCESEARCH_H
