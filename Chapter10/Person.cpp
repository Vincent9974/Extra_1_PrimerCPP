#include "Person.h"
#include <cstring>
#include <iostream>

using namespace std;

Person::Person(const string &ln, const char *fn):lname(ln)
{
    strncpy(fname, fn, sizeof(fname)-1);
    fname[sizeof(fname)-1];
}

void Person::show() const
{
    cout << "first name: " << fname << endl;
    cout << "last  name:" << lname << endl;

}

void Person::FormalShow() const
{
    cout << "last  name:" << lname << endl;
    cout << "first name: " << fname << endl;
}
