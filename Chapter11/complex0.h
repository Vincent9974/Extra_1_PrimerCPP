#pragma once
#include <ostream>

class Complex
{
private:
    double realNumbers;
    double imaginaryNumbers;

public:
    Complex(double real, double imaginary);
    Complex();
    ~Complex();

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator*(double scalar) const;
    Complex operator~ () const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& complex);
};