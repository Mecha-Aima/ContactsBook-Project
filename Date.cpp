#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
bool Date::compare(const Date& other) const {
    // Compare two date instances
    // Returns true if this date is greater than the other date, else false
    // Assuming the date is compared based on year, then month, then day
    // You can modify this logic as per your requirements
    if (year > other.year)
        return true;
    else if (year == other.year && month > other.month)
        return true;
    else if (year == other.year && month == other.month && day > other.day)
        return true;
    else
        return false;
}
Date& Date::getDate() {
    return *this;
}
void Date::setDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}
void Date::displayDate() const {
    cout << "Date: " << month << "/" << day << "/" << year << endl;
}