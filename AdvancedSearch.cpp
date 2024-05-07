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
    List<int> indices(query.size());

    for (size_t j = 0; j < query.size(); j++)
    {
        // Find all occurrences of query[j] in lowerStr
        size_t pos = 0;
        while ((pos = lowerStr.find(query[j], pos)) != string::npos)
        {
            if (indices.is_empty() || pos > indices[indices.size() - 1]) {
                indices.append(pos);
            }
            pos++;
        }
    }

    return indices.size() == query.size();
}


List<Contact> AdvanceSearch::get_results()
{
    return searchResults;
}

void AdvanceSearch::update_history(HistoryObject& h, SearchHistory &sh)
{
    sh.add_search_item(h);
}
