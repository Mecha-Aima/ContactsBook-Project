#include "AdvancedSearch.h"
#include "HistoryObject.h"
using namespace std;
// Constructor
AdvanceSearch::AdvanceSearch() :
    maxSize(200), searchResults(maxSize), item_count(0) {}

// Destructor
AdvanceSearch::~AdvanceSearch() { }

// Convert to lowercase
string lower(string s)
{
    for (char& c : s) {
        c = std::tolower(c);
    }
    return s;
}

// Method to perform the search
void AdvanceSearch::perform_search(std::string query, ContactsBook &book)
{
    if(query.empty())
    {
        searchResults.clear();
        item_count = 0;
        return;
    }
    if(item_count > 0)
    {
        searchResults.clear();
        item_count = 0;
    }

    string q = lower(query);
    for (size_t i = 0; i < book.total_contacts(); i++)
    {
        if (is_query_in_string(q, book[i].get_first_name()) ||
            is_query_in_string(q, book[i].get_last_name()) ||
            is_query_in_string(q, book[i].get_email_address()) ||
            is_query_in_string(q, book[i].get_mobile_number())) {
            searchResults.append(book[i]);
            item_count++;
        }
    }
}

bool AdvanceSearch::is_query_in_string(const std::string& query, const std::string& str)
{
    string lowerStr = lower(str);
    size_t queryIndex = 0;

    for (char ch : lowerStr)
    {
        if (ch == query[queryIndex])
        {
            queryIndex++;
        }

        if (queryIndex == query.size())
        {
            return true;  // All characters in the query have been found in order
        }
    }

    return false;  // Not all characters in the query were found in order
}



List<Contact> AdvanceSearch::get_results()
{
    return searchResults;
}

void AdvanceSearch::update_history(HistoryObject& h, SearchHistory &sh)
{
    sh.add_search_item(h);
}
