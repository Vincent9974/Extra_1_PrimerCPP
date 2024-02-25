// stack.cpp -- Stack class methods
#include "stack.h"
#include <iostream>

stack::stack(int n) : size(n), top(0)
{
    pitems = new Item[size];
}

stack::stack(const stack &st) : size(st.size), top(st.top)
{
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }
}

stack::~stack()
{
    delete[] pitems;
}

bool stack::isempty() const
{
    return top == 0;
}

bool stack::isfull() const
{
    return top == size;
}

bool stack::push(const Item &item)
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::pop(Item &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
    {
        return false;
    }
}

stack &stack::operator=(const stack &st)
{
    if (this == &st)
    {
        return *this;
    }

    delete[] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }

    return *this;
}

