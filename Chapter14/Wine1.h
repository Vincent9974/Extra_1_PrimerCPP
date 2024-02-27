#pragma once
#include<string>
#include <valarray>
#include "Pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine1: private PairArray
{
private:
    int years;


public:
    Wine1(const char* l, int y, const int yr[], const int bot[]);
    Wine1(const char* l, int y);
    
    void GetBottles();
    void show() const;
    const int Label() const;
    int sum() const;
};