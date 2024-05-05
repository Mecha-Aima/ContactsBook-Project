#ifndef TIME_H
#define TIME_H
#include "Comparator.h"
class Time : public Comparator<Time> {
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time(int hours, int minutes, int seconds);
    Time(const Time& other) = default;
    Time& operator=(const Time& other) = default;
    bool operator==(const Time& other) const;
    bool compare(const Time& other, bool (*fptr)(const Time& t1, const Time& t2)) const override;
    Time& get_time();
    void set_time(int hours, int minutes, int seconds);
    static bool less_than(const Time& t1, const Time& t2);
    static bool greater_than(const Time& t1, const Time& t2);
};
#endif
