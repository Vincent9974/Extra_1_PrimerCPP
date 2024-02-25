// stock.h
#ifndef STOCK_H_
#define STOCK_H_

#include <iostream>

class Stock
{
private:
    char *company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock(); // 默认构造函数
    Stock(const char *co, int n = 0, double pr = 0.0);
    ~Stock(); // 析构函数
    friend std::ostream &operator<<(std::ostream &os, const Stock &st);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    
};

#endif
