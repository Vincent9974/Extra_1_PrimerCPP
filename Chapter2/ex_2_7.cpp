#include<windows.h>
#include<iostream>
using namespace std;


//1．编写一个C++程序，它显示您的姓名和地址。
void _2_7_1()
{
    string name;
    string address;
    cout << "请输入姓名:" << endl;
    cin >> name;
    cout << "请输入地址:" << endl;
    cin >> address;
    cout << "姓名:" << name << "\n" << "地址:" << address << endl;

}

//2．编写一个C+程序，它要求用户输入一个以long为单位的距离，
//   然后将它转换为码(一long 等于220码)。
int long2ma(int _long)
{
    return _long * 220;
}

//2．编写一个CH程序，它要求用户输入一个以long 为单位的距离，然后将它转换为码(一long 等于220码).
void _2_7_2()
{
    cout << "请输入long" << endl;
    int _long;
    cin >> _long;
    if(!std::is_same<decltype(_long), int>::value)
    {
        std::cout << "_long is an integer." << std::endl;
    }
    cout << "码为:" << long2ma(_long) << endl;
}

void mice()
{
    cout << "Three blind mice" << endl;
}

void run()
{
    cout << "See how they run" << endl;
}

// 编写一个C++程序，它使用3个用户定义的函数（包括main())，并生成下面的输出:
void _2_7_3()
{
    mice();
    mice();
    run();
    run();
}

// 4．编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月，如下所示:
void _2_7_4()
{
    cout << "Enter your age:" << endl;
    int age;
    cin >> age;
    cout << "Month:" << age*12 << endl;
}

// 5．编写一个程序，其中的main()调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值)。
//    该程序按下面的格式要求用户输入摄氏温度值，并显示结果:

float celsius2fahrenheit(float Celsius)
{
    return Celsius * 1.8 + 32.0;
}

void _2_7_5()
{
    cout << "Please enter a Celsius value:\n";
    float Celsius;
    cin >> Celsius;
    cout << Celsius <<" degrees Celsius is " << celsius2fahrenheit(Celsius) << " degrees Fahrenheit." << endl;
}

// 6.编写一个程序，其 main()调用一个用户定义的函数
// (以光年值为参数，并返回对应天文单位的值)。
// 该程序按下面的格式要求用户输入光年值,并显示结果:
// Enter the number of light years: 4.2
// 4.2 light years = 265608 astronomical units.

float lightYear2astronomicalUnits(float lightYear)
{
    return lightYear * 63240;
}

void _2_7_6()
{
    cout << "Enter the number of light years:";
    float lightYear;
    cin >> lightYear;
    cout << endl;
    float astronomicalUnits = lightYear2astronomicalUnits(lightYear);
    cout << lightYear << " light years = " << astronomicalUnits << " astronomical units." << endl;
}

// 7．编写一个程序，要求用户输入小时数和分钟数。
// 在main()函数中，将这两个值传递给一个void 函数，
// 后者以下面这样的格式显示这两个值:
// Enter the number of hours: 9
// Enter the number of minutes:28Time:9:28

void showTime(int hours, int minutes)
{
    cout << "Time: " << hours << ":" << minutes << endl;
}

void _2_7_7()
{
    int hours;
    int minutes;
    cout <<"Enter the number of hours:\n";
    cin >> hours;
    cout <<"Enter the number of minutes:\n";
    cin >> minutes;
    showTime(hours, minutes);
}

int main()
{
    //_2_7_1();

    //_2_7_2();

    //_2_7_3();

    //_2_7_4();

    //_2_7_5();

    //_2_7_6();

    _2_7_7();

    system("pause");
    return 0;
}