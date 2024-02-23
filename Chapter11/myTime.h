#pragma once
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void addMin(int m);
    void addHr(int h);
    void reset(int h = 0, int m =0);
    Time operator+(const Time & t) const;
    void show() const;

      // Declare friend functions for overloaded operators
    friend Time operator-(const Time &t1, const Time &t2);
    friend Time operator*(double n, const Time &t);
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
};