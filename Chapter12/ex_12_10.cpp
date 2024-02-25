#include <iostream>
#include "Cow.h"
#include "String2.h"
#include "Stock.h"
#include "Stack.h"
#include "Customer.h"
#include "Queue.h"
#include <ctime>


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

    Item1 item1;

    // 演示 push 和 pop
    for (int i = 0; i < 3; ++i)
    {
        st1.push(i);
    }

    while (!st1.isempty())
    {
        st1.pop(item1);
        std::cout << "Popped item: " << item1 << std::endl;
    }
}

const int MIN_PER_HR = 60;
bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}
void _12_10_5()
{
    srand(time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    int cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    int turnaways = 0;
    int customers = 0;
    int served = 0;
    int sum_line = 0;
    int wait_time = 0;
    int line_wait = 0;

        for (int cycle = 0; cycle < cyclelimit; ++cycle) {
        if (newcustomer(min_per_cust)) {
            if (line.isfull()) {
                turnaways++;
            } else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isempty()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0) {
            wait_time--;
        }
        sum_line += line.queuecount();
    }

    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << "average wait time: " << (double)line_wait / served << " minutes\n";
    } else {
        cout << "No customers!\n";
    }
    cout << "Done!\n";


}


int main()
{

    //_12_10_1();

    //_12_10_2();

    //_12_10_3();

    //_12_10_4();

    _12_10_5();

    return 0;
}