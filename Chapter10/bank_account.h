#pragma once
#include <string>
using namespace std;

class BankAccount
{
private:
    string account_holder;
    string account_number;
    double balance;

public:
    // 默认构造函数
    BankAccount();

    // 代参构造函数
    BankAccount(const string& holder, const string& number, double initialBalance = 0.0);
    
    // 显示账户信息
    void displayInfo() const;

    // 存款
    void deposit(double amount);

    // 取款
    void withdraw(double amount);

};
