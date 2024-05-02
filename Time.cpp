#include "Time.h"
#include <iostream>
using namespace std;
//Parametraized Constructor 
Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}
bool Time::compare(const Time& other) const {
    // Compare two time instances
    // Returns true if this time is greater than the other time, else false
    // Assuming the time is compared based on hours, then minutes, then seconds
    // You can modify this logic as per your requirements
    if (hours > other.hours)
        return true;
    else if (hours == other.hours && minutes > other.minutes)
        return true;
    else if (hours == other.hours && minutes == other.minutes && seconds > other.seconds)
        return true;
    else
        return false;
}
Time& Time::getTime() {
    return *this;
}
void Time::setTime(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}
void Time::displayTime() const {
    cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
}