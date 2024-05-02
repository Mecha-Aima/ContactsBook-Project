#include"HistoryObject.h"
#include<iostream>
using namespace std;
// Constructor with separate hour, minute, second, day, month, year parameters
HistoryObject::HistoryObject(int hour, int minute, int second, int day, int month, int year) :
    time(hour, minute, second), date(day, month, year) {}
// Constructor with Time and Date objects
HistoryObject::HistoryObject(const Time& time, const Date& date) : time(time), date(date) {}

HistoryObject& HistoryObject::display() {
    return *this;
}

Time& HistoryObject::get_time() {
    return time;
}

void HistoryObject::set_time(int hour, int minute, int second) {
    time.set_time(hour, minute, second);
}

Date& HistoryObject::get_date() {
    return date;
}

void HistoryObject::set_date(int day, int month, int year) {
    date.set_date(day, month, year);
}
// Copy constructor
HistoryObject::HistoryObject(const HistoryObject& other) : time(other.time), date(other.date) {}
// Assignment operator
HistoryObject& HistoryObject::operator=(const HistoryObject& other) {
    time = other.time;
    date = other.date;
    return *this;
}

bool HistoryObject::less_than(const HistoryObject& h1, const HistoryObject& h2) {
    // Returns true if h1 is less than h2, else false
    // Assuming the history object is compared based on date, then time
    if (h1.date.compare(h2.date, Date::less_than))
        return true;
    else if (h1.date.compare(h2.date, Date::less_than) && h1.time.compare(h2.time, Time::less_than))
        return true;
    else
        return false;
}

bool HistoryObject::greater_than(const HistoryObject& h1, const HistoryObject& h2) {
    // Returns true if h1 is greater than h2, else false
    // Assuming the history object is compared based on date, then time
    if (h1.date.compare(h2.date, Date::greater_than))
        return true;
    else if (h1.date == h2.date && h1.time.compare(h2.time, Time::greater_than))
        return true;
    else
        return false;
}

bool HistoryObject::compare(const HistoryObject& other, bool (*fptr)(const HistoryObject& h1, const HistoryObject& h2)) const {
    // Compare two history object instances
    return fptr(*this, other);
}

bool HistoryObject::operator==(const HistoryObject& other) const {
    return (time == other.time && date == other.date);
}


