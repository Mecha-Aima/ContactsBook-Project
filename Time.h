#ifndef TIME_H
#define TIME_H
class Time {
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time(int hours, int minutes, int seconds);
    bool compare(const Time& other) const;
    Time& getTime();
    void setTime(int hours, int minutes, int seconds);
    void displayTime() const;
};
#endif