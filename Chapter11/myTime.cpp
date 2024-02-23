#include "myTime.h"
#include <iostream>

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::addMin(int m)
{
    minutes +=m ;
    minutes %= 60;
    hours += minutes/60;
}

void Time::addHr(int h)
{
    hours += h;
}

void Time::reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = this->minutes + t.minutes;
    sum.hours = this->hours + t.hours + (sum.minutes/60);
    sum.minutes %= 60;
    return sum;
}

void Time::show() const
{
    std::cout << hours << " hours, " << minutes << " minutes.";
}

Time operator-(const Time &t1, const Time &t2)
{
    Time diff;
    int tot1, tot2;
    tot1 = t1.minutes + 60 * t1.hours;
    tot2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

Time operator*(double n, const Time &t)
{
    Time result;
    long totalMinutes = t.hours * 60 * n + t.minutes * n;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes.";
    return os;
}