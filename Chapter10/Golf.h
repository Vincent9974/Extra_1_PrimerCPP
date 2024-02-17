#pragma once

#include <iostream>
#include <cstring>

const int Len = 40;

class Golf {
private:
    char fullname[Len];
    int handicap;

public:
    // 默认构造函数
    Golf();

    // 带参数的构造函数
    Golf(const char* name, int hc);

    // 交互版本的 setgolf，使用构造函数实现
    void setgolf();

    // 显示 golf 数据
    void showgolf() const;
};