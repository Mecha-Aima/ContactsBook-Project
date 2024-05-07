#include "AdvancedSearch.h"
#include "HistoryObject.h"
using namespace std;
// Constructor
AdvanceSearch::AdvanceSearch() :
    maxSize(200), searchResults(maxSize) {}

// Destructor
AdvanceSearch::~AdvanceSearch() { }

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
<<<<<<< HEAD
    for (size_t i = 0; i < book.total_contacts(); i++)
    {
        List<int> indices(15);
        string name = lower(book[i].get_first_name());
=======
    bool match;
    for (size_t i = 0; i < book.total_contacts(); i++)
    {
        List<int> indices(15);
        string name = lower(book.get_contacts()->get_first_name());
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2
        string q = lower(query);
        
        for (size_t j = 0; j < query.length(); j++)
        {
            int index = name.find(q[j]);
            if (index == string::npos)
            {
<<<<<<< HEAD
=======
                match = false;
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2
                break;
            }
            // q = abc: a -> b -> c
            if (indices.is_empty())
<<<<<<< HEAD
                indices.append(index);
=======
                indices.append(index > indices[indices.size() - 1]);
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2
            else if(index > indices[indices.size() - 1]) {
                indices.append(index);
            }
        }
        // Check if all characters in the query have been found

        if(indices.size() == query.length()){
<<<<<<< HEAD
            searchResults.append(book[i]);
=======
            searchResults.append();
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2
        }
    }
}

<<<<<<< HEAD
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

=======
// // Method to update frequently searched contacts
// void AdvanceSearch::update_frequently_searched(const Contact& contact) {
//     bool found = false;
//     // Iterate through frequently_searched array
//     for (int i = 0; i < 5; i++) {
//         if (frequently_searched[i].get_first_name() == contact.get_first_name() &&
//             frequently_searched[i].get_last_name() == contact.get_last_name()) {
//             found = true;
//             break;
//         }
//     }
//     // If the contact is not found, add it to the frequently_searched array
//     if (!found) {
//         for (int i = 4; i > 0; i--) {
//             frequently_searched[i] = frequently_searched[i - 1];
//         }
//         frequently_searched[0] = contact;
//     }
// }
// // Getter for frequently searched contacts
// const Contact* AdvanceSearch::get_frequently_searched() const {
//     // Reserve memory for a new array with a size of 5
//     const Contact* frequently_searched_array = new Contact[5];
//     // Copy the contents of frequently_searched to frequently_searched_array
//     for (int i = 0; i < 5; i++) {
//         frequently_searched_array[i].get_first_name() = frequently_searched[i].get_first_name();
//         frequently_searched_array[i].get_last_name() = frequently_searched[i].get_last_name();
//         frequently_searched_array[i].get_mobile_number() = frequently_searched[i].get_mobile_number();
//         frequently_searched_array[i].get_email_address() = frequently_searched[i].get_email_address();
//         frequently_searched_array[i].get_address()->get_city() = frequently_searched[i].get_address()->get_city();
//         frequently_searched_array[i].get_address()->get_country() = frequently_searched[i].get_address()->get_country();
//         frequently_searched_array[i].get_address()->get_house() = frequently_searched[i].get_address()->get_house();
//         frequently_searched_array[i].get_address()->get_street() = frequently_searched[i].get_address()->get_street();
//     }
//     return frequently_searched_array;
// }
// // Method to add a search result
// void AdvanceSearch::add_search_result(const Contact& result) {
//     if (item_count < max_size) {
//         searchResults[item_count++] = result;
//     }
//     else {
//         // Handle the case where searchResults array is full
//         // For example, you can overwrite the oldest result
//         if (item_count >= max_size) {
//             for (int i = 1; i < max_size; i++) {
//                 searchResults[i - 1] = searchResults[i];
//             }
//             searchResults[max_size - 1] = result;
//         }
//     }
//     // Update frequently searched contacts
//     update_frequently_searched(result);
// }
// // Getter for search results
// const Contact* AdvanceSearch::get_search_results() const {
//     // Reserve memory for a new array with the same size as searchResults
//     const Contact* search_results_array = new Contact[item_count];
//     // Copy the contents of searchResults to search_results_array
//     for (int i = 0; i < item_count; i++) {
//         search_results_array[i].get_first_name() = searchResults[i].get_first_name();
//         search_results_array[i].get_last_name() = searchResults[i].get_last_name();
//         search_results_array[i].get_mobile_number() = searchResults[i].get_mobile_number();
//         search_results_array[i].get_address()->get_city() = searchResults[i].get_address()->get_city();
//         search_results_array[i].get_address()->get_country() = searchResults[i].get_address()->get_country();
//         search_results_array[i].get_address()->get_house() = searchResults[i].get_address()->get_house();
//         search_results_array[i].get_address()->get_street() = searchResults[i].get_address()->get_street();
//     }
//     return search_results_array;
// }
//cctype library
// std::string str = "Hello";

// // Convert each character in the string to lower case
// for (char& c : str) {
// 	c = std::tolower(c);
// }

// std::cout << "Lower case string: " << str << std::endl;
>>>>>>> 1063c0e4201d08ac3ca1c98f17b17fdb2938afe2
