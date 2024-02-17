#pragma once

struct customer
{
    char fullname[35];
    double payment;
};

typedef customer Item;
static const int MAX = 10;
class Stack
{
private:
    Item items[MAX];
    int top;
    double totalPayment;

public:
    Stack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    double getTotalPayment() const;
};