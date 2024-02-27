#pragma once
#include <string>
#include <iostream>

class Person
{
private:
    std::string firstName;
    std::string lastName;

public:
    Person(std::string fname, std::string lname)
        : firstName(fname), lastName(lname){};
    virtual void Show() const { std::cout << firstName << " " << lastName << std::endl; };
};

class Gunslinger : public virtual Person
{
private:
    double drawTime;
    int notches;

public:
    Gunslinger(const std::string &first, const std::string &last,
               double time, int marks) : Person(first, last), drawTime(time), notches(marks){};
    double Draw() const { return drawTime; }

    void Show() const override
    {
        Person::Show();
        std::cout << "Draw Time: " << Draw() << " seconds" << std::endl;
        std::cout << "Notches on the gun: " << notches << std::endl;
    }
};

class Card
{
public:
    enum Suits{
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    };
    int Numbers;
};

class PokerPlayer : public virtual Person
{
public:
    PokerPlayer(const std::string &first, const std::string &last)
    : Person(first, last) {}
    int Draw() const
    {
        // 返回一个1~52的随机数
        return rand() % 52 + 1;
    }

};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(const std::string& first, const std::string& last,
    double time, int marks)
    :Person(first, last),
    Gunslinger(first, last, time, marks),
    PokerPlayer(first, last) {};

    // 返回坏蛋拔枪的时间
    double Gdraw() const { return Gunslinger::Draw(); }

    // 返回下一张扑克牌的值
    int Cdraw() const { return PokerPlayer::Draw(); }

    // Show 方法合适的定义
    void Show() const override
    {
        Person::Show();
        std::cout << "Draw time: " << Gdraw() << " seconds\n";
        std::cout << "Notches on the gun: " << Gunslinger::Draw() << std::endl;
        std::cout << "Next poker card value: " << Cdraw() << std::endl;
    }

};