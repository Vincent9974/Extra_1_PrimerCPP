#pragma once
#include <stdexcept>
#include <cmath>
#include <iostream>

class CustomException : public std::logic_error {
private:
    double param1;
    double param2;

public:
    CustomException(const std::string &message, double p1, double p2)
        : std::logic_error(message), param1(p1), param2(p2) {}

    void reportValues() const {
        std::cout << "Parameter 1: " << param1 << std::endl;
        std::cout << "Parameter 2: " << param2 << std::endl;
    }
};

class bad_hmean : public std::logic_error
{
public:
    bad_hmean() : std::logic_error("bad_hmean exception: hmean() called with invalid arguments") {}
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean() : std::logic_error("bad_gmean exception: gmean() called with invalid arguments") {}
};

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}

double hmean1(double a, double b) {
    if (a == -b)
        throw CustomException("bad_hmean exception: hmean() called with invalid arguments", a, b);
    return 2.0 * a * b / (a + b);
}

double gmean1(double a, double b) {
    if (a < 0 || b < 0)
        throw CustomException("bad_gmean exception: gmean() called with invalid arguments", a, b);
    return std::sqrt(a * b);
}