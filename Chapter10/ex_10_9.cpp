#include <iostream>
#include "bank_account.h"
#include "Person.h"
#include "Golf.h"
#include "sales.h"
#include "Stack.h"
#include "Move.h"
#include "Plorg.h"
#include "List.h"

using namespace std;

void _10_9_1()
{
    BankAccount bk1("vc", "123456", 4500);
    bk1.displayInfo();
    cout << "---" << endl;

    bk1.deposit(10000);
    bk1.displayInfo();
    cout << "---" << endl;

    bk1.withdraw(5000);
    bk1.displayInfo();
    cout << "---" << endl;

    bk1.deposit(-1);
    bk1.withdraw(10000000);
    bk1.withdraw(-1);
}

void _10_9_2()
{
    Person one;
    Person two("Smthecraft");
    Person three("Dimwiddy", "Sam");

    one.show();
    cout << endl;
    one.FormalShow();
    cout << "----" << endl;

    two.show();
    cout << endl;
    two.FormalShow();
    cout << "----" << endl;

    three.show();
    cout << endl;
    three.FormalShow();
    cout << "----" << endl;
}

void _10_9_3()
{
    Golf golfer1;       // 使用默认构造函数创建对象
    golfer1.showgolf(); // 显示默认初始化的数据

    Golf golfer2("John Doe", 12); // 使用带参数的构造函数创建对象
    golfer2.showgolf();           // 显示带参数初始化的数据

    Golf golfer3;       // 创建对象
    golfer3.setgolf();  // 通过交互版本的 setgolf 设置数据
    golfer3.showgolf(); // 显示通过 setgolf 设置的数据
}

void _10_9_4()
{
    // 使用Sales类
    Sales sales1; // 默认构造函数
    sales1.showSales();

    double salesData[] = {1200.5, 1500.2, 1800.8, 2000.0};
    Sales sales2(salesData); // 构造函数，接受销售数据数组
    sales2.showSales();

    Sales sales3; // 交互式构造函数
    sales3.setSales();
    sales3.showSales();
}



typedef customer Item;
void _10_9_5()
{
    Stack stack;

    // 添加 customer 到栈中
    customer c1 = {"John Doe", 100.0};
    customer c2 = {"Jane Smith", 200.0};

    stack.push(c1);
    stack.push(c2);

    // 获取并报告 payment 总和
    std::cout << "Total payment: $" << stack.getTotalPayment() << std::endl;

    // 弹出 customer，并再次报告 payment 总和
    customer poppedCustomer;
    stack.pop(poppedCustomer);

    std::cout << "Popped customer: " << poppedCustomer.fullname << " with payment: $" << poppedCustomer.payment << std::endl;
    std::cout << "Updated total payment: $" << stack.getTotalPayment() << std::endl;
}

void _10_9_6()
{
    Move move1(3, 4);
    Move move2;
    move1.showMove();
    move2.showMove();
    move2.moveAdd(move1);
    move2.showMove();
    move2.reset();
    move2.showMove();
    move2.reset(3, 4);
    move2.showMove();
}

void _10_9_7()
{
    Plorg plorg1;
    Plorg plorg2("CustomPlorg", 75);

    plorg1.report();
    plorg2.report();

    plorg1.setSatisfactionIndex(60);
    plorg1.report();
}


void _10_9_8()
{
    List myList;

    // 添加数据项到列表
    myList.addItem(10);
    myList.addItem(20);
    myList.addItem(30);

    // 访问并执行操作
    myList.visit([](int &item)
    {
        std::cout << "Item: " << item << std::endl;
        // 在这里执行其他操作，根据需要修改 lambda 函数
    });
}

int main()
{

    //_10_9_1();

    //_10_9_2();

    //_10_9_3();

    //_10_9_4();

    //_10_9_5();

    //_10_9_6();

    //_10_9_7();

    _10_9_8();

    return 0;
}
