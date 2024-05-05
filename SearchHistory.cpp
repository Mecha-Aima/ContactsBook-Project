#include "SearchHistory.h"
#include <fstream>
#include <iostream>
using namespace std;
SearchHistory::SearchHistory() :frequentSearch(5), history(100) {}
bool SearchHistory::check_frequent_search() {
    int threshold = 5; // Define a threshold for a search to be considered frequent
    int currentSearchCount = 0; // Initialize the count for the current search
    // Assuming history is an array of HistoryObject instances
    for (int i = 0; i < historySize; i++) {
        // Use the overloaded == operator from HistoryObject class to check if the current history item matches the frequent search
        if (frequentSearch[i] == history[i]) { // Using the overloaded operator
            currentSearchCount++; // Increment the count if the current search matches the frequent search
        }
    }
    // Check if the current search count exceeds the threshold for it to be considered frequent
    return currentSearchCount >= threshold;
}
void SearchHistory::update_frequent_search(Contact& contact) {
    int threshold = 5; // Define the threshold locally
    // Initialize a variable to store the count of occurrences of the provided contact
    int contactCount = 0;
    // Iterate through the history array to count occurrences of the provided contact
    for (int i = 0; i < historySize; ++i) {
        // Assuming each HistoryObject has a Contact object stored directly
        if (history[i].getContact() == contact) { 
            contactCount++;
        }
    }
    // If the count of occurrences exceeds the threshold, update the frequentSearch
    //if (contactCount > threshold) {
    //    // Update frequentSearch with the provided contact
    //    frequentSearch = contact;
    //}// I am getting error on that specific condition saying that no operator = matches these operands
}
void SearchHistory::add_search_item(Contact& contact, HistoryObject& historyObject) {
    // Assuming history is an array of HistoryObject instances
    if (historySize < 100) {
        history[historySize++] = historyObject;
    }
    else {
        throw ("Cannot add more ");
        // Handle the case where history array is full
        //cout << "History array is full. Cannot add more items." << endl;
    }
}
//void SearchHistory::save_to_file(string historyFile, string top5File) {
//    
//}
