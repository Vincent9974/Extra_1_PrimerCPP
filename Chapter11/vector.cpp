#include "vector.h"
#include <math.h>
#include <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
const double Rad_to_deg = 45.0 / atan(1.0);

void VECTOR::Vector::set_mag()
{
    mag = sqrt(x * x + y * y);
}

void VECTOR::Vector::set_ang()
{
    if(x == 0.0 && y ==0.0)
    {
        ang = 0.0;
    }
    else
    {
        ang = atan2(y, x);
    }
}

void VECTOR::Vector::set_x()
{
    x = mag * cos(ang);
}

void VECTOR::Vector::set_y()
{
    y = mag * sin(ang);
}

VECTOR::Vector::Vector() : x(0.0), y(0.0), mag(0.0), ang(0.0),
                           mode(RECT) {}

VECTOR::Vector::Vector(double n1, double n2, Mode form)
{
    mode = form;
    if(form == RECT)
    {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    }

    else if (form == POL)
    {
        mag = n1;
        ang = n2 / Rad_to_deg;
        set_x();
        set_y();
    }
    else
    {
        std::cout << "Incorrect 3rd argument to Vector() -- ";
        std::cout << "vector set to 0 \n";
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
}

VECTOR::Vector::~Vector()
{
}

void VECTOR::Vector::polar_mode()
{
    mode = POL;
}
void VECTOR::Vector::rect_mode()
{
    mode = RECT;
}

Vector VECTOR::Vector::operator+(const Vector &b) const
{
    return Vector(x + b.x, y + b.y);
}
Vector VECTOR::Vector::operator-(const Vector &b) const
{
    return Vector(x - b.x, y - b.y);
}
Vector VECTOR::Vector::operator-() const
{
    return Vector(-x, -y);
}

Vector VECTOR::Vector::operator*(double n) const
{
    return Vector( x * n, n * y);
}

Vector operator*(double n, const Vector &a)
{
    return a * n;
}

double Vector::magval() const {
    return sqrt(x * x + y * y);
}

double Vector::angval() const {
    if (x == 0.0 && y == 0.0) {
        return 0.0;
    } else {
        return atan2(y, x);
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    if (v.mode == Vector::RECT)
        os << "(x,y)= (" << v.x << "," << v.y << ") ";
    else if (v.mode == Vector::POL)
        os << "(m, a)=(" << v.mag << ", " << v.ang * Rad_to_deg << ")";
    else
        os << "Vector object mode is invalid";

    return os;
}
} // end namespace VECTOR
