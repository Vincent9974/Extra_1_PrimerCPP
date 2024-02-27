#pragma once
#include <string>

class Worker
{
private:
    std::string name;
    int age;

public:
    Worker(std::string n, int a);
    int getAge() const;
    std::string getName() const;
};