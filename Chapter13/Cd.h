#pragma once

// 基类 Cd 的声明
class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    // 构造函数
    Cd(const char* s1, const char* s2, int n, double x);
    // 虚析构函数
    virtual ~Cd();
    // 虚报告函数
    virtual void Report() const;
    // 虚赋值运算符重载
    virtual Cd& operator=(const Cd& d);
};

// 派生类 Classic 的声明
class Classic : public Cd
{
private:
    char mainWork[100];

public:
    // 构造函数
    Classic(const char* s1, const char* s2, const char* main, int n, double x);
    // 虚析构函数
    ~Classic();
    Classic();
    // 虚报告函数
    void Report() const override;
    // 虚赋值运算符重载
    Classic& operator=(const Classic& c);
};

// 其他声明
void Bravo(const Cd& disk);