#include "Plorg.h"
#include <cstring>
#include <iostream>

using namespace std;

void Plorg::setSatisfactionIndex(int ci)
{
    satisfactionIndex = ci;
}

void Plorg::report()const
{
    std::cout << "Plorg Name: " << name << ", Satisfaction Index: " << satisfactionIndex << std::endl;
}

Plorg::Plorg(const char* n, int ci) {
    // 复制名称，截断超过19个字符的部分
    strncpy(name, n, MAX_NAME_LENGTH);
    name[MAX_NAME_LENGTH] = '\0';  // 确保以 null 终止

    satisfactionIndex = ci;
}