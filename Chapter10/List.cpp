#include "List.h"
#include <iostream>

List::List()
{
    items = new int[MAX_SIZE];
    size = 0;
}

List::~List(){}

bool List::isEmpty() const
{
    return size == 0;
}

bool List::isFull() const
{
    return size == MAX_SIZE;
}

void List::addItem(const int &item)
{
    if (!isFull()) {
        items[size++] = item;
    } else {
        std::cout << "List is full. Cannot add more items.\n";
    }
}

void List::visit(void (*pf)(int &))
{
    for(int i = 0; i < size; ++i)
    {
        pf(items[i]);
    }
}
