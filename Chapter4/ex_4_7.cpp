#include <iostream>
#include <string>
#include <Array>

using namespace std;
// 1．编写一个C++程序，如下述输出示例所示的那样请求并显示信息:

void _4_13_1()
{
    char grade;
    string firstName;
    string lastName;
    int age;

    std::cout << "What is your first name? ";
    getline(cin, firstName);
    std::cout << "What is your last name? ";
    getline(cin, lastName);

    std::cout << "What letter grade do you deserve? ";
    cin >> grade;

    std::cout << "What is your age? ";
    cin >> age;

    // 向上调整成绩
    if (grade >= 'A' && grade <= 'C')
    {
        grade++;
    }

    // 显示信息
    std::cout << "\nName: " << lastName << ", " << firstName << std::endl;
    std::cout << "Grade: " << char(grade + 1) << std::endl; // 加一来显示下一个等级
    std::cout << "Age: " << age << std::endl;
}

void _4_13_2()
{
    using namespace std;
    const int ArSize = 20;
    string name;
    string dessert;

    cout << "Enter your name: \n";
    getline(cin, name); // 使用 getline 获取一行输入

    cout << "Enter your favorite dessert: \n";
    getline(cin, dessert);

    cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
}

void _4_13_3()
{
    string firstName;
    string lastName;
    string name;

    cout << "Enter your first name:" << endl;
    cin >> firstName;

    cout << "Enter your last name:" << endl;
    cin >> lastName;

    name = lastName + ", " + firstName;

    cout << "Here's the information in a single string: " << name << endl;
}

void _4_13_4()
{
    string firstName;
    string lastName;
    string name;

    cout << "Enter your first name:" << endl;
    cin >> firstName;

    cout << "Enter your last name:" << endl;
    cin >> lastName;

    name.append(lastName).append(", ").append(firstName);

    cout << "Here's the information in a single string: " << name << endl;
}

struct CandyBar
{
    string brand;
    float weight;
    int calories;
};

void _4_13_5()
{
    CandyBar snack{"Mocha Munch", 2.3, 350};
    cout << snack.brand << endl;
    cout << snack.weight << endl;
    cout << snack.calories << endl;
}

void _4_13_6()
{
    array<CandyBar, 3> Candy;
    Candy[0] = {"Mocha 1", 1.3, 150};
    Candy[1] = {"Mocha 2", 2.3, 250};
    Candy[2] = {"Mocha 3", 3.3, 350};

    for (auto candy : Candy)
    {
        cout << candy.brand << endl;
        cout << candy.weight << endl;
        cout << candy.calories << endl;
    }
}

struct Pizza
{
    string companyName;
    float calibre;
    float weight;
};

void _4_13_7()
{
    Pizza pizza;

    cout << "Enter the companyName:" << endl;
    cin >> pizza.companyName;
    cout << "Enter the calibre:" << endl;
    cin >> pizza.calibre;
    cout << "Enter the weight:" << endl;
    cin >> pizza.weight;


    cout << pizza.companyName << endl;
    cout << pizza.calibre << endl;
    cout << pizza.weight << endl;
}

void _4_13_8()
{
    Pizza* pizza = new Pizza;

    cout << "Enter the calibre:" << endl;
    cin >> pizza->calibre;    
    cout << "Enter the companyName:" << endl;
    cin >> pizza->companyName;
    cout << "Enter the weight:" << endl;
    cin >> pizza->weight;


    cout << pizza->companyName << endl;
    cout << pizza->calibre << endl;
    cout << pizza->weight << endl;

}

void _4_13_9()
{
    CandyBar* Candy = new CandyBar[3];
    Candy[0] = {"Mocha 1", 1.3, 150};
    Candy[1] = {"Mocha 2", 2.3, 250};
    Candy[2] = {"Mocha 3", 3.3, 350};

}

void _4_13_10()
{
    array<int,3> score;
    int sum=0;
    float avg = 0;
    cout << "Enter the score 0:" << endl;
    cin >> score[0];
    cout << "Enter the score 1:" << endl;
    cin >> score[1];
    cout << "Enter the score 2:" << endl;
    cin >> score[2];

    for(auto s:score)
    {
        sum = sum + s;
    }
    avg = sum/score.size();
    cout << avg;
}

int main()
{
    //_4_13_1();

    // _4_13_2();

    //_4_13_3();

    //_4_13_4();

    //_4_13_5();

    //_4_13_6();

    //_4_13_7();

    //_4_13_8();

    //_4_13_9();

    _4_13_10();
}