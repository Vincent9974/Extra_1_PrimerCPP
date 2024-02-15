#include "golf.h"
#include <iostream>
#include <cstring>

void setgolf(golf &g, const char *name, int hc)
{
    strncpy(g.fullname, name, Len);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    using namespace std;
    cout << "Enter the name:";
    cin.getline(g.fullname, Len);

    if (g.fullname[0] == '\0') {
        return 0; // Return 0 if an empty string is entered
    }


    cout << "Enter the golfer's handicap: ";
    cin >> g.handicap;

    cin.get();
    return 0;
}

void handicap(golf &g, int hc) {
    g.handicap = hc;
}

void showgolf(const golf &g) {
    using namespace std;
    cout << "Name: " << g.fullname << ", Handicap: " << g.handicap << endl;
}