#include "Wine1.h"
#include <iostream>
#include <string>

Wine1::Wine1(const char* l, int y, const int yr[], const int bot[]) 
: PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), years(y) {}

Wine1::Wine1(const char* l, int y) 
: PairArray(ArrayInt(y), ArrayInt(y)), years(y) {}

void Wine1::GetBottles()
{
    std::cout << "Enter data for " << years << " year(s):\n";
    for (int i = 0; i < years; ++i) {
        std::cout << "Enter year: ";
        std::cin >> PairArray::first()[i];

        std::cout << "Enter bottles for that year: ";
        std::cin >> PairArray::second()[i];
    }
}

void Wine1::show() const
{
    std::cout << "Wine: " << Label() << "\n";
    std::cout << "Year\tBottles\n";
    for (int i = 0; i < years; ++i) {
        std::cout << PairArray::first()[i] << "\t" << PairArray::second()[i] << "\n";
    }
}

const int Wine1::Label() const {
    return PairArray::first()[0];
}

int Wine1::sum() const
{
    return PairArray::second().sum();
}
