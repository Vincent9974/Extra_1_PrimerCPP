#include "Wine.h"
#include <iostream>

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
:label(l), years(y), data(ArrayInt(yr,y), ArrayInt(bot,y)){}

Wine::Wine(const char* l, int y) 
: label(l), years(y), data(ArrayInt(y), ArrayInt(y)) {}

void Wine::GetBottles() {
    std::cout << "Enter " << label << " data for " << years << " years:\n";
    for (int i = 0; i < years; ++i) {
        std::cout << "Enter year: ";
        int yr, bot;
        std::cin >> yr;
        std::cout << "Enter bottles for that year: ";
        std::cin >> bot;
        data.first()[i] = yr;
        data.second()[i] = bot;
    }
}

void Wine::show() const {
    std::cout << "Wine: " << label << "\n";
    std::cout << "Year\tBottles\n";
    for (int i = 0; i < years; ++i) {
        std::cout << data.first()[i] << "\t" << data.second()[i] << "\n";
    }
}