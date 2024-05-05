#ifndef DATE_H
#define DATE_H
#include "Comparator.h"
class Date : Comparator<Date> {
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);
    Date(const Date& other) = default;
    Date& operator=(const Date& other) = default;
    bool compare(const Date& other, bool (*fptr)(const Date& a, const Date& b)) const override;
    Date& get_date();
    void set_date(int day, int month, int year);
    static bool less_than(const Date& d1, const Date& d2);
    static bool greater_than(const Date& d1, const Date& d2);
    bool operator==(const Date& other) const;
};
#endif
