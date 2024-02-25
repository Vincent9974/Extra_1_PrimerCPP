// stock.cpp
#include <cstring>
#include "stock.h"

Stock::Stock() // 默认构造函数
{
    company = nullptr;
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *co, int n, double pr)
{
    int len = std::strlen(co);
    company = new char[len + 1];
    std::strcpy(company, co);

    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock() // 析构函数
{
    delete[] company;
}

void Stock::buy(int num, double price)
{
    if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    if (num < 0)
    {
        std::cerr << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cerr << "You can't sell more than you have! "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream &operator<<(std::ostream &os, const Stock &st)
{
    os << "Company: " << st.company
       << " Shares: " << st.shares << std::endl
       << " Share Price: $" << st.share_val
       << " Total Worth: $" << st.total_val;
    return os;
}
