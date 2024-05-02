#pragma once
#ifndef HISTORYOBJECT_H
#define HISTORYOBJECT_H
#include "Time.h"
#include "Date.h"
class HistoryObject {
private:
    Time time;
    Date date;
public:
    // Constructors
    HistoryObject(int hour, int minute, int second, int day, int month, int year);
    HistoryObject(Time time, Date date);
    // Methods
    bool compare(const HistoryObject& other) const;
    Time& getTime();
    void setTime(int hour, int minute, int second);
    Date& getDate();
    void setDate(int day, int month, int year);
    void display() const;
};
#endif 