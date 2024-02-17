#pragma once

class List
{
private:
    static const int MAX_SIZE = 100;
    int *items;
    char list[MAX_SIZE];
    int size;

public:
    List();
    ~List();
    bool isEmpty() const;
    bool isFull() const;
    void addItem(const int &item);
    void visit(void(*pf)(int &));
};