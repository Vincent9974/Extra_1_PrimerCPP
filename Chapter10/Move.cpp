#include "Move.h"
#include <iostream>
using namespace std;

Move::Move(double a, double b) : x(a), y(b) {}

void Move::showMove() const
{
    cout << "x:" << x << "\ty:" << y << endl;
}

void Move::moveAdd(const Move &m)
{
    this->x += m.x;
    this->y += m.y;
}

void Move::reset(double a, double b)
{
    this->x = a;
    this->y = b;
}