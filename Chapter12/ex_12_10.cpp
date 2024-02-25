#include <iostream>
#include "Cow.h"
#include "String2.h"
#include "Stock.h"
#include "Stack.h"
#include <queue>
#include "Customer.h"

using namespace std;

void _12_10_1()
{
    // Cow c1;
    // c1.ShowCow();

    Cow c2("安格斯","爱吃草", 200);
    c2.ShowCow();

    Cow c3 = Cow(c2);
    c3.ShowCow();

    Cow c4 = c3;
    c4.ShowCow();
}

void _12_10_2()
{
    String s1(" and I am a C++ student. ");
    String s2 = "Please enter your name: ";
    String s3;

    std::cout << s2;
    std::cin >> s3;

    s2 = "My name is " + s3;
    std::cout << s2 << ".\n";

    s2 = s2 + s1;
    s2.Stringup();
    std::cout << "The string\n" << s2 << "\ncontains " << s2.CharCount('A')
              << " 'A' characters in it.\n";

    String s4 = "red";
    String rgb[3] = {s4, "green", "blue"};

    std::cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;

    while (std::cin >> ans) {
        ans.Stringlow();

        for (int i = 0; i < 3; i++) {
            if (ans == rgb[i]) {
                std::cout << "That's right!\n";
                success = true;
                break;
            }
        }

        if (success) {
            break;
        } else {
            std::cout << "Try again!\n";
        }
    }

    std::cout << "Bye.\n";
}

void _12_10_3()
{
    Stock stock1("NanoSmart", 12, 20.0);
    std::cout << "Using constructor to create stock1\n";
    stock1.buy(15, 18.125);
    cout << stock1 << endl;
    stock1.sell(400, 20.0);
    cout << stock1 << endl;
}

void _12_10_4()
{
    stack st1(5); // 创建大小为5的栈
    stack st2 = st1; // 使用复制构造函数
    stack st3;

    st3 = st2; // 使用赋值运算符

    Item item;

    // 演示 push 和 pop
    for (int i = 0; i < 3; ++i)
    {
        st1.push(i);
    }

    while (!st1.isempty())
    {
        st1.pop(item);
        std::cout << "Popped item: " << item << std::endl;
    }
}




int main()
{

    //_12_10_1();

    //_12_10_2();

    //_12_10_3();

    _12_10_4();

    return 0;
}