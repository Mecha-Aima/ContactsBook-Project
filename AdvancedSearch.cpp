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
}

// Method to perform the search
void AdvanceSearch::perform_search(std::string query, ContactsBook &book)
{
    // Match the search by first_name, last_name, email_address or mobile_number
    // query: adn, matches: Adnan, Anodomini, ashely
    // string.find(char/string) -> index of first occ
    // consecutive
    // a = 2; b = 3;  
    // indices = name.find(q[i]) : if(name.find(q[i]) > indices[indices.size()-1] -> then add i to indices
    // indices.size() == query.length() -> match = true
    for (size_t i = 0; i < book.total_contacts(); i++)
    {
        List<int> indices(15);
        string name = lower(book[i].get_first_name());
    for (size_t i = 0; i < book.total_contacts(); i++)
    {
        List<int> indices(15);
        string name = lower(book.get_contacts()->get_first_name());
        string q = lower(query);
        
        for (size_t j = 0; j < query.length(); j++)
        {
            int index = name.find(q[j]);
            if (index == string::npos)
            {
                break;
            }
            // q = abc: a -> b -> c
            if (indices.is_empty())
                indices.append(index);
            else if(index > indices[indices.size() - 1]) {
                indices.append(index);
            }
        }
        // Check if all characters in the query have been found

        if(indices.size() == query.length()){
            searchResults.append(book[i]);
            item_count++;
        }
    }
}

List<string> AdvanceSearch::get_results()
{
    List<string> names;
    for (size_t i = 0; i < searchResults.size(); i++)
    {
        names.append(searchResults[i].get_first_name() + " " + searchResults[i].get_last_name());
    }
    return names;
}

void AdvanceSearch::update_history(HistoryObject& h, SearchHistory &sh)
{
    sh.add_search_item(h);
}
