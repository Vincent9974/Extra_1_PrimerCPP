// #include <iostream>
// #include <vector>
// #include <list>
// #include <string>
// #include <cstring>
// #include <thread>
// #include <functional>
// #include <mutex>
// #include <chrono>

// class MyString {
// public:
//     // 移动构造函数
//     MyString(MyString&& other) noexcept
//         : data(other.data) {
//             other.data = nullptr; // 避免资源被释放两次
//         }
    
//     // 其他成员函数和定义...
//     // 构造函数：从 C 风格字符串构造
//     MyString(const char* str) : data(nullptr) {
//         if (str != nullptr) {
//             size_t size = std::strlen(str) + 1;
//             data = new char[size];
//             std::strcpy(data, str);
//         }
//     }
//         // 打印字符串
//     void print() const {
//         std::cout << (data ? data : "Empty") << std::endl;
//     }
//     // 移动赋值运算符
//     MyString& operator=(MyString&& other) noexcept {
//         if (this != &other) {
//             delete[] data;       // 释放当前对象的资源
//             data = other.data;   // 移动资源
//             other.data = nullptr; // 防止资源被释放两次
//         }
//         return *this;
//     }


// private:
//     char* data;
// };


// MyString createString() {
//     // 创建一个临时对象并返回，这是一个右值
//     return MyString("Hello");
// }

// void originalFunction() {
//     std::cout << "Executing the original function." << std::endl;
// }

// void wrapperFunction(std::function<void()> func)
// {
//     std::cout << "Executing some logic before the function." << std::endl;
//     func();
//     std::cout << "Executing some logic after the function." << std::endl;
// }


// class Component {
// public:
//     virtual void operation() const {
//         std::cout << "Executing the original operation." << std::endl;
//     }
// };

// class Wrapper : public Component {
// private:
//     Component* component;

// public:
//     Wrapper(Component* comp) : component(comp) {}

//     void operation() const override {
//         std::cout << "Executing some logic before the operation." << std::endl;
//         component->operation();
//         std::cout << "Executing some logic after the operation." << std::endl;
//     }
// };




// int main() {
//     // int x = 5;
//     // decltype(x) y; // 使用与 x 相同的类型声明变量 y

//     // y = 10;

//     // std::cout << "x: " << x << std::endl;
//     // std::cout << "y: " << y << std::endl;
//     using myInt = int;
//     using MathFunction = double(*)(double, double);


//     myInt x = 5;
//     double y = 3.14;

//     decltype(x + y) result; // 使用表达式 x + y 的类型声明变量 result

//     result = x + y;

//     std::cout << "Result: " << result << std::endl;

//     int && ref = 42;

//     // 使用移动构造函数创建 MyString 对象
//     MyString a("Hello");
//     MyString b = std::move(a); // 移动 a 的资源给 b

//     // 此时 a 的资源为空，而 b 拥有 "Hello" 字符串资源
//     std::cout << "Object a: ";
//     a.print();
    
//     std::cout << "Object b: ";
//     b.print();

//     MyString c("Hello");
//     MyString d("World");

//     // 使用移动赋值运算符，将 b 的资源移动给 a
//     c = std::move(d);

//     // 此时 a 拥有 "World" 字符串资源，而 b 的资源为空
//     std::cout << "Object a: ";
//     c.print();
//     std::cout << "Object b: ";
//     d.print();

//     auto add = [](int a, int b) ->int
//     {
//         return a + b;
//     };


//     // 使用Lambda函数
//     int res = add(3, 4);

//     std::cout << "Result: " << res << std::endl;

//     int xx = 10;
//     auto square = [xx]() -> int
//     {
//         return xx * xx;
//     };

//     int res1 = square();

//     std::cout << "Square of x: " << res1 << std::endl;

//     wrapperFunction(originalFunction);

//     Component* original = new Component();
//     Wrapper* wrapped = new Wrapper(original);

//     wrapped->operation();

//     delete original;
//     delete wrapped;


//     return 0;
// }




