#pragma once
#ifndef DATE_H
#define DATE_H
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);
    bool compare(const Date& other) const;
    Date& getDate();
    void setDate(int day, int month, int year);
    void displayDate() const;
};
#endif