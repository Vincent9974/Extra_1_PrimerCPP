#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include "Cpmv.h"

using namespace std;

class Z200
{
private:
    int j;
    char ch;
    double z;

public:
    Z200(int jv, char chv, double zv) : j(jv), ch(chv), z(zv) {}
};

void ex_18_11_01()
{
    double x = 8.8;
    std::string s = "what can i say?";
    int k(99);
    Z200 zip(200, 'Z', 0.675);

    std::vector<int> ai(5);
    int ar[5] = {3, 9, 4, 7, 1};

    for (size_t i = 0; i < ai.size(); ++i)
    {
        ai[i] = ar[i];
    }

    for (const auto &elem : ai)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

double up(double x) { return 2.0 * x; }
void r1(const double &rx) { cout << rx << endl; }
void r2(double &rx) { cout << rx << endl; }
void r3(double &&rx) { cout << rx << endl; }
void ex_18_11_02()
{
    double w = 10.0;

    r1(w);     // 合法，引用参数指向 w，是 const 引用
    r1(w + 1); // 合法，引用参数指向临时值 (w + 1)，是 const 引用
    r1(up(w)); // 合法，引用参数指向 up(w) 的结果，是 const 引用

    r2(w); // 合法，引用参数指向 w，是非 const 引用
    // r2(w + 1);    // 不合法，不能将临时值 (w + 1) 绑定到非 const 引用
    // r2(up(w));    // 不合法，引用参数指向 up(w)，是非 const 引用

    // r3(w);        // 不合法，不能将左值 w 绑定到右值引用
    r3(std::move(w));
    r3(w + 1); // 合法，能将临时值 (w + 1) 绑定到右值引用
    r3(up(w)); // 合法，引用参数指向 up(w) 的结果，是右值引用
}

double upb1(double x) { return 2.0 * x; }
void rb1(double &rx) { cout << "double & rx\n"; }
void rb1(double &&rx) { cout << "double && rx\n"; }

double up_c(double x) { return 2.0 * x; }
void r1_c(const double &rx) { cout << "const double & rx\n"; }
void r1_c(double &&rx) { cout << "double && rx\n"; }

void ex_18_11_03()
{
    double w = 10.0;
    rb1(w);       // 调用 r1(double &rx)，输出 "double & rx"
    rb1(w + 1);   // 调用 r1(double &&rx)，输出 "double && rx"
    rb1(upb1(w)); // 调用 r1(double &&rx)，输出 "double && rx"

    cout << "===" << endl;
    double wc = 10.0;
    r1_c(wc);
    r1_c(wc + 1);
    r1_c(up_c(wc));
}

template <typename T>
void show2(double x, T &fp)
{
    std::cout << x << "->" << fp(x) << '\n';
}

double f1(double x)
{
    return 1.8 * x + 32;
}

void ex_18_11_06()
{
    auto lambda = [](double x)
    { return 1.8 * x + 32; };
    show2(18.0, lambda);
}

const int size = 5;
template <typename T>
void sum(std::array<double, size> a, T &fp)
{
    for (auto pt = a.begin(); pt != a.end(); ++pt)
    {
        fp(*pt);
    }
}

void ex_18_11_07()
{
    double total = 0.0;
    auto lambda = [&total](double w)
    { total += w; };

    std::array<double, size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};

    // 调用 sum()，将 lambda 表达式作为第二个参数传递
    sum(temp_c, lambda);
    // 输出结果
    std::cout << "total: " << total << '\n';
}

template <typename T>
T average_list(std::initializer_list<T> il)
{
    T sum = 0;
    for (const auto &elem : il)
    {
        sum += elem;
    }
    return sum / il.size();
}

void ex_18_12_01()
{
    using namespace std;

    // list of double deduced from list contents
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;

    // list of int deduced from list contents
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;

    // forced list of double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
}

void ex_18_12_02()
{
    Cpmv obj1("Q123", "Z456");
    Cpmv obj2("Q789", "Z012");

    // 调用移动构造函数
    Cpmv obj3 = std::move(obj1);

    // 调用移动赋值运算符
    obj2 = std::move(obj3);

    // 调用operator+()
    // Cpmv result = obj1 + obj2;

    // 显示各个对象的内容
    obj1.Display();
    obj2.Display();
    obj3.Display();
    // result.Display();
}


// 基本情况的实现
long double sum_value() {
    return 0.0;
}

template <typename T, typename... Args>
long double sum_value(T value, Args... args)
{
    return static_cast<long double>(value) + sum_value(args...);
}


void ex_18_12_03()
{
        // 测试
    long double result = sum_value(1, 2.5, 3.7, 4.2, 5);
    
    std::cout << "Sum: " << result << std::endl;
}


void ex_18_12_04()
{
    auto print_number = [](int x) {std::cout << x << " ";};
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 使用默认的升序排序
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted numbers in ascending order: ";
    
    // 使用 for_each 和有名称的 lambda 打印每个数字
    std::for_each(numbers.begin(), numbers.end(), print_number);
    
    std::cout << std::endl;
}

int main()
{

    // ex_18_11_01();

    // ex_18_11_02();

    // ex_18_11_03();

    // ex_18_11_06();

    // ex_18_11_07();

    // ex_18_12_01();

    // ex_18_12_02();

    // ex_18_12_03();

    ex_18_12_04();

    return 0;
}