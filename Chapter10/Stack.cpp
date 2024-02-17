#include "Stack.h"
#include <iostream>

Stack::Stack() : top(0), totalPayment(0.0) {}

bool Stack::isEmpty() const
{
    return top == 0;
}

bool Stack::isFull() const
{
    return top == MAX;
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = items[--top];
        totalPayment -= item.payment; // 从总和中减去被弹出的 payment
        return true;
    }
    else
    {
        std::cout << "Stack is empty, pop failed.\n";
        return false;
    }
}

bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        totalPayment += item.payment; // 累加 payment 到总和
        return true;
    }
    else
    {
        std::cout << "Stack is full, push failed.\n";
        return false;
    }
}

double Stack::getTotalPayment() const
{
    return totalPayment;
}