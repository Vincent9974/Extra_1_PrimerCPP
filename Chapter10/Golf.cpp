#include "Golf.h"

// 默认构造函数的实现
Golf::Golf() {
    std::strcpy(fullname, "No name");
    handicap = 0;
}

// 带参数的构造函数的实现
Golf::Golf(const char* name, int hc) {
    std::strncpy(fullname, name, Len - 1);
    fullname[Len - 1] = '\0';
    handicap = hc;
}

// 交互版本的 setgolf，使用构造函数实现
void Golf::setgolf() {
    std::cout << "Enter golfer's name: ";
    std::cin.getline(fullname, Len);

    std::cout << "Enter golfer's handicap: ";
    std::cin >> handicap;
    std::cin.get();  // 消耗输入缓冲区中的换行符
}

// 显示 golf 数据的实现
void Golf::showgolf() const {
    std::cout << "Golfer's name: " << fullname << std::endl;
    std::cout << "Golfer's handicap: " << handicap << std::endl;
}