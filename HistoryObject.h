#ifndef HISTORYOBJECT_H
#define HISTORYOBJECT_H
#include "Time.h"
#include "Date.h"
#include <iostream>
class HistoryObject: public Comparator<HistoryObject> {
private:
    Time time;
    Date date;
public:
    // Constructors
    HistoryObject();
    HistoryObject(int hour, int minute, int second, int day, int month, int year);
    HistoryObject(const Time& time, const Date& date);
    // Destructor
    ~HistoryObject() {}
    // Copy constructor
    HistoryObject(const HistoryObject& other);
    HistoryObject& display();

    // Methods
    bool compare(const HistoryObject& a, const HistoryObject& b, bool (*fptr)(const HistoryObject& h1, const HistoryObject& h2)) const override;
    Time& get_time();
    void set_time(int hour, int minute, int second);
    Date& get_date();
    void set_date(int day, int month, int year);
    static bool less_than(const HistoryObject& h1, const HistoryObject& h2);
    static bool greater_than(const HistoryObject& h1, const HistoryObject& h2);

    // Assignment operator
    HistoryObject& operator=(const HistoryObject& other);
    // Equality operator
    bool operator==(const HistoryObject& other) const;
    // This is temporary
    friend std::ostream& operator<<(std::ostream& os, const HistoryObject& history_object);

};
#endif 