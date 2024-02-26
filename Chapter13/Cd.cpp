#include "Cd.h"
#include <cstring>
#include <iostream>
using namespace std;


// Cd 类的实现
Cd::Cd(const char* s1, const char* s2, int n, double x)
{
    std::strncpy(performers, s1, 49);
    performers[49] = '\0';
    std::strncpy(label, s2, 19);
    label[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::~Cd()
{
    // 这里可以添加清理资源的代码，比如释放动态分配的内存
}

void Cd::Report() const
{
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << " minutes" << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
    if (this == &d)
        return *this;

    std::strncpy(performers, d.performers, 49);
    performers[49] = '\0';
    std::strncpy(label, d.label, 19);
    label[19] = '\0';
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

// Classic 类的实现
Classic::Classic(const char* s1, const char* s2, const char* main, int n, double x)
    : Cd(s1, s2, n, x)
{
    std::strncpy(mainWork, main, 99);
    mainWork[99] = '\0';
}

Classic::~Classic()
{
    // 这里可以添加清理资源的代码，比如释放动态分配的内存
}

Classic::Classic():Cd("","",0,0.0),mainWork(""){}

void Classic::Report() const
{
    Cd::Report(); // 调用基类的 Report 函数
    std::cout << "Main work: " << mainWork << std::endl;
}

Classic& Classic::operator=(const Classic& c)
{
    if (this == &c)
        return *this;

    Cd::operator=(c); // 调用基类的赋值运算符重载

    std::strncpy(mainWork, c.mainWork, 99);
    mainWork[99] = '\0';

    return *this;
}

// Bravo 函数的实现
void Bravo(const Cd& disk)
{
    disk.Report();
}