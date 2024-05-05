#ifndef HISTORYOBJECT_H
#define HISTORYOBJECT_H
#include "Time.h"
#include "Date.h"
#include "Contact.h" 
class HistoryObject : public Comparator<HistoryObject> {
private:
    Time time;
    Date date;
    Contact contact; 
public:
    // Constructors
    HistoryObject(int hour, int minute, int second, int day, int month, int year);
    HistoryObject(const Time& time, const Date& date);
    // Destructor
    ~HistoryObject() {}
    // Copy constructor
    HistoryObject(const HistoryObject& other);
    HistoryObject& display();
    // Methods
    bool compare(const HistoryObject& other, bool (*fptr)(const HistoryObject& h1, const HistoryObject& h2)) const override;
    Time& get_time();
    void set_time(int hour, int minute, int second);
    Date& get_date();
    void set_date(int day, int month, int year);
    Contact& getContact(); // Declaration of getContact() method
    static bool less_than(const HistoryObject& h1, const HistoryObject& h2);
    static bool greater_than(const HistoryObject& h1, const HistoryObject& h2);
    // Assignment operator
    HistoryObject& operator=(const HistoryObject& other);
    // Equality operator
    bool operator==(const HistoryObject& other) const;
};

#endif
