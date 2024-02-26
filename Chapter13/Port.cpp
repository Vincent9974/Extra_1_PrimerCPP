#include "Port.h"

Port::Port(const char *br, const char *st, int b):bottles(b)
{
    brand = new char[strlen(br) + 1];
    std::strcpy(brand, br);
    std::strcpy(style, st);
}

Port::Port(const Port &p):bottles(p.bottles)
{
    brand = new char[strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
}

Port::~Port()
{
    delete[] brand;
}

Port &Port::operator=(const Port &p)
{
    if(this == &p)
    {
        return *this;
    }
        delete[] brand;

    brand = new char[strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;

    return *this;
}

Port &Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port &Port::operator-=(int b)
{
    if (bottles >= b)
    { bottles -= b;}
    return *this;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Style: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort():Port()
,nickname(nullptr), year(0){}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y)
:Port(br,"vintage",b),year(y)
{
    nickname = new char[strlen(nn) + 1];
    std::strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort &vp)
{
    delete[] nickname;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
        return *this;

    Port::operator=(vp); // 调用基类的赋值运算符重载

    delete[] nickname;

    nickname = new char[strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);

    year = vp.year;

    return *this;
}



// VintagePort 显示信息的方法
void VintagePort::show() const {
    Port:Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
}

// VintagePort 友元输出运算符重载
std::ostream &operator<<(std::ostream &os, const VintagePort &vp) {
    os << (const Port &)vp; // 调用基类的输出运算符重载
    os << "Nickname: " << vp.nickname << ", ";
    os << "Year: " << vp.year << std::endl;
    return os;
}