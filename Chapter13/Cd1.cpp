#include "Cd1.h"
#include <iostream>
#include <cstring>
using namespace std;

Cd1::Cd1(const char *s1, const char *s2, int n, double x):
selections(n), playtime(x)
{
    performers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    strcpy(performers, s1);
    strcpy(label, s2);
}

Cd1::~Cd1(){}

Cd1::Cd1():performers(nullptr),label(nullptr), 
selections(0), playtime(0.0){}

Cd1::Cd1(const Cd1 &d):
selections(d.selections), playtime(d.playtime)
{
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
}

void Cd1::CdReport() const
{
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
    std::cout << "=========" << std::endl;
}

Cd1 &Cd1::operator=(const Cd1 &d)
{
    if(this == &d)
    {
        return *this;
    }
    delete[] performers;
    delete[] label;

    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);

    selections = d.selections;
    label = d.label;

    return *this;
}

Classic1::Classic1(const char *s1, const char *s2, int n, double x, const char *main)
: Cd1(s1, s2, n, x)
{
    mainWork = new char[strlen(main) + 1];
    std::strcpy(mainWork, main);
}

Classic1::Classic1(const Classic1 &c):Cd1(c)
{
    mainWork = new char[strlen(c.mainWork) + 1];
    std::strcpy(mainWork, c.mainWork);
}

Classic1::Classic1():Cd1(), mainWork(nullptr){}

Classic1::~Classic1()
{
    delete[] mainWork;
}

void Classic1::CdReport() const
{
    Cd1::CdReport();
    std::cout << "Main Work: " << mainWork << std::endl;
}

Classic1 &Classic1::operator=(const Classic1 &c)
{
    if (this == &c)
        return *this;

    Cd1::operator=(c);

    delete[] mainWork;

    mainWork = new char[strlen(c.mainWork) + 1];
    std::strcpy(mainWork, c.mainWork);

    return *this;
}

// Bravo 函数的实现
void Bravo1(const Cd1& disk)
{
    disk.CdReport();
}