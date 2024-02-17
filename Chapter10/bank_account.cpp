#include "bank_account.h"
#include <iostream>

using namespace std;


BankAccount::BankAccount(): balance(0.0){}

BankAccount::BankAccount(const string &holder,const  string &number, double initialBalance) 
: account_holder(holder), account_number(number), balance(initialBalance){}

void BankAccount::displayInfo() const
{
    cout << "Account holder:" << account_holder <<endl;
    cout << "Account number:" << account_number <<endl;
    cout << "Balance:" << balance <<endl;
}

void BankAccount::deposit(double amount)
{
    if(amount > 0)
    {
        balance += amount;
        cout << "Depostie of $" << amount << " successful." << endl;
    }
    else
    {
        cout << "Invalid depost amount." << endl;
    }
}

void BankAccount::withdraw(double amount)
{
    if(amount > 0 && balance >= amount)
    {
        balance -= amount;
        cout << "With draw $" << amount << endl;
    }
    else
    {
        cout << "Invalid withdraw or out of balance." << endl;
    }
}
