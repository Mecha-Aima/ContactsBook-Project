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
        List<int> indices(15);
        string name = lower(book[i].get_first_name() + book[i].get_last_name() + book[i].get_email_address() + book[i].get_mobile_number());
        
        for (size_t j = 0; j < q.length(); j++)
        {
            // Find all occurrences of q[j] in name
            size_t pos = 0;
            while ((pos = name.find(q[j], pos)) != string::npos)
            {
                if (indices.is_empty() || pos > indices[indices.size() - 1]) {
                    indices.append(pos);
                }
                pos++;
            }
        }
        if(indices.size() == q.length()){
            searchResults.append(book[i]);
            item_count++;
        }
    }
}


List<Contact> AdvanceSearch::get_results()
{
    return searchResults;
}

void AdvanceSearch::update_history(HistoryObject& h, SearchHistory &sh)
{
    sh.add_search_item(h);
}
