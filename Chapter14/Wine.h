#pragma once
#include<string>
#include <valarray>
#include "Pair.h"


typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
    std::string label;
    int years;
    PairArray data;
    

public:
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);
    void GetBottles();
    const std::string& Label() const { return label; }
    int sum() const { return data.second().sum(); }
    void show() const;
};
