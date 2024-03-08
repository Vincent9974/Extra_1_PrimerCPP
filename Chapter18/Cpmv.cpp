#include "Cpmv.h"
#include <iostream>
using namespace std;

Cpmv::Cpmv()
{
    cout << "Default Constructor Called\n";
}

Cpmv::Cpmv(std::string q, std::string z) : pi(new Info{q, z})
{
    cout << "Constructor Called\n";
}

Cpmv::Cpmv(const Cpmv &cp) : 
pi(new Info{cp.pi->qcode, cp.pi->zcode})
{
    std::cout << "Copy Constructor Called\n";
}

Cpmv::Cpmv(Cpmv &&mv) : pi(mv.pi)
{   
    mv.pi = nullptr;
    std::cout << "Move Constructor Called\n";
}

Cpmv::~Cpmv()
{
    delete pi;
    std::cout << "Destructor Called\n";
}

// 拷贝赋值运算符
Cpmv &Cpmv::operator=(const Cpmv &cp) {
    if (this == &cp) {
        return *this;
    }

    delete pi;
    pi = new Info{cp.pi->qcode, cp.pi->zcode};

    std::cout << "Copy Assignment Operator Called\n";
    return *this;
}

// 移动赋值运算符
Cpmv &Cpmv::operator=(Cpmv &&mv) {
    if (this == &mv) {
        return *this;
    }

    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;

    std::cout << "Move Assignment Operator Called\n";
    return *this;
}

// + 运算符重载
Cpmv Cpmv::operator+(const Cpmv &obj) const {
    std::cout << "+ Operator Overloaded\n";
    return Cpmv(this->pi->qcode + obj.pi->qcode, this->pi->zcode + obj.pi->zcode);
}

// 显示信息
void Cpmv::Display() const {
    if (pi) {
        std::cout << "qcode: " << pi->qcode << ", zcode: " << pi->zcode << '\n';
    } else {
        std::cout << "Empty Cpmv\n";
    }
}