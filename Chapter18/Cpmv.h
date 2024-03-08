#pragma once
#include <string>


class Cpmv {
public:
    struct Info {
        std::string qcode;
        std::string zcode;
    };

private:
    Info *pi;

public:
    // 默认构造函数
    Cpmv();

    // 构造函数
    Cpmv(std::string q, std::string z);

    // 拷贝构造函数
    Cpmv(const Cpmv &cp);

    // 移动构造函数
    Cpmv(Cpmv &&mv);

    // 析构函数
    ~Cpmv();

    // 拷贝赋值运算符
    Cpmv &operator=(const Cpmv &cp);

    // 移动赋值运算符
    Cpmv &operator=(Cpmv &&mv);

    // + 运算符重载
    Cpmv operator+(const Cpmv &obj) const;

    // 显示信息
    void Display() const;
};