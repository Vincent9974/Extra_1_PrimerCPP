#pragma once
#include <cstring>

class Cd1
{
private:
    char* performers;
    char* label;
    int selections;
    double playtime;
public:
    Cd1(const char* s1, const char*s2, int n, double x);
    ~Cd1();
    Cd1();
    Cd1(const Cd1& d);
    virtual void CdReport() const;
    Cd1& operator=(const Cd1& d);
};

class Classic1: public Cd1
{
private:
    char* mainWork;
public:
    Classic1(const char* s1, const char* s2, int n, double x, const char* main);
    Classic1(const Classic1& c);
    Classic1();
    ~Classic1();
    void CdReport() const override;
    Classic1& operator=(const Classic1& c);
};

void Bravo1(const Cd1& disk);