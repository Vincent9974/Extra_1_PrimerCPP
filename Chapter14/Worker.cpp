#include "Worker.h"

Worker::Worker(std::string n, int a):name(n), age(a){}

int Worker::getAge() const
{
    return age;
}

std::string Worker::getName() const
{
    return name;
}
