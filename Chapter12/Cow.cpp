#include "Cow.h"
#include <string.h>
#include <iostream>

Cow::Cow():weight(0.0)
{
    strncpy(name, "cow", 20);
    hobby = nullptr;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    strncpy(name,nm,20);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby,ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    strncpy(name,c.name,20);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby,c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete[] hobby;
    std::cout << "delete" << std::endl;
}

Cow &Cow::operator=(const Cow &c)
{
    if(this != &c)
    {
    strncpy(name,c.name,20);
    delete[] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    }

    return *this;
}

void Cow::ShowCow() const
{
    std::cout << "name: " << name << std::endl;
    std::cout << "hobby: " << hobby << std::endl;
    std::cout << "weight: " << weight << std::endl;
}
