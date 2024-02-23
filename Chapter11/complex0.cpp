#include "complex0.h"
#include <iostream>


Complex::Complex(double real, double imaginary)
:realNumbers(real), imaginaryNumbers(imaginary){}

Complex::Complex()
{
    realNumbers = 0.0;
    imaginaryNumbers = 0.0;
}

Complex::~Complex(){}

Complex Complex::operator+(const Complex &other) const 
{
    return Complex(realNumbers + other.realNumbers,
    imaginaryNumbers + other.imaginaryNumbers);
}

Complex Complex::operator-(const Complex &other) const
{
    return Complex(realNumbers - other.realNumbers,
    imaginaryNumbers - other.imaginaryNumbers);
}

Complex Complex::operator*(const Complex &other) const
{
    double resultReal = realNumbers * other.realNumbers - imaginaryNumbers * other.imaginaryNumbers;
    double resultImaginary = realNumbers * other.imaginaryNumbers + imaginaryNumbers * other.realNumbers;
    return Complex(resultReal, resultImaginary);
}

Complex Complex::operator*(double scalar) const
{
    return Complex(realNumbers  * scalar,
    imaginaryNumbers * scalar);
}

Complex Complex::operator~() const
{
    return Complex(realNumbers, -imaginaryNumbers);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.realNumbers << ", " << c.imaginaryNumbers << "i)";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& complex)
{
    std::cout << "Enter real part: ";
    is >> complex.realNumbers;
    std::cout << "Enter imaginary part: ";
    is >> complex.imaginaryNumbers;
    return is;
}
