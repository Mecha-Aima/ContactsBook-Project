#include"HistoryObject.h"
#include<iostream>
using namespace std;
// Constructor with separate hour, minute, second, day, month, year parameters
HistoryObject::HistoryObject(int hour, int minute, int second, int day, int month, int year) :
    time(hour, minute, second), date(day, month, year) {}
// Constructor with Time and Date objects
HistoryObject::HistoryObject(Time time, Date date) : time(time), date(date) {}
bool HistoryObject::compare(const HistoryObject& other) const {
    // Compare two HistoryObject instances
    // Compares the time first, then date if time is equal
    if (time.compare(other.time))
        return true;
    else if (time.compare(other.time) == false && date.compare(other.date))
        return true;
    else
        return false;
}
Time& HistoryObject::getTime() {
    return time;
}
void HistoryObject::setTime(int hour, int minute, int second) {
    time.setTime(hour, minute, second);
}
Date& HistoryObject::getDate() {
    return date;
}
void HistoryObject::setDate(int day, int month, int year) {
    date.setDate(day, month, year);
}
void HistoryObject::display() const {
    cout << "History Object:" << endl;
    cout << "Time: ";
    time.displayTime();
    cout << "Date: ";
    date.displayDate();
}