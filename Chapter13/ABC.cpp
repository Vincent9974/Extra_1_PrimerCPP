#include "ABC.h"



ABC::ABC(const char* l, int r)
    : rating(r)
{
    label = new char[strlen(l) + 1];
    std::strcpy(label, l);
}

ABC::ABC(const ABC& a)
    : label(nullptr), rating(a.rating)
{
    label = new char[strlen(a.label) + 1];
    std::strcpy(label, a.label);
}

ABC::~ABC()
{
    delete[] label;
}

ABC& ABC::operator=(const ABC& a)
{
    if (this == &a)
        return *this;

    delete[] label;

    label = new char[strlen(a.label) + 1];
    std::strcpy(label, a.label);
    rating = a.rating;

    return *this;
}


baseDMA::baseDMA(const char* l, int r)
    : ABC(l, r)
{
}

baseDMA::~baseDMA()
{
}

void baseDMA::View() const
{
    std::cout << "Label: " <<   std::endl;
    std::cout << "Rating: " <<  std::endl;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r)
    : ABC(l, r)
{
    color = new char[strlen(c) + 1];
    std::strcpy(color, c);
}

lacksDMA::~lacksDMA()
{
    delete[] color;
}

void lacksDMA::View() const
{
}



