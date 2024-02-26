#include <iostream>
#include "Cd.h"
#include "Cd1.h"
#include "ABC.h"
#include "Port.h"

void _13_11_1()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2("Alfred Brendel", "Philips", "Piano Sonata in B flat, Fantasia in c", 2, 57.17);
    Cd *pcd = &c1;

    std::cout << "Using object directly:\n";
    c1.Report(); // 使用 Cd 对象的方法
    c2.Report(); // 使用 Classic 对象的方法

    std::cout << "Using type Cd* pointer to objects:\n";
    pcd->Report(); // 使用 Cd 对象的方法（通过指针）
    pcd = &c2;
    pcd->Report(); // 使用 Classic 对象的方法（通过指针）

    std::cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    std::cout << "Testing assignment:\n";
    Classic copy;
    copy = c2;
    copy.Report();
}

void _13_11_2()
{
    Cd1 c1("Beatles", "Capitol", 14, 35.5);
    Classic1 c2("Alfred Brendel", "Philips", 2, 57.17, "Piano Sonata in B flat, Fantasia in c");
    Cd1 *pcd = &c1;

    std::cout << "Using object directly:\n";
    c1.CdReport(); // 使用 Cd 对象的方法
    c2.CdReport(); // 使用 Classic 对象的方法

    std::cout << "Using type Cd* pointer to objects:\n";
    pcd->CdReport(); // 使用 Cd 对象的方法（通过指针）
    pcd = &c2;
    pcd->CdReport(); // 使用 Classic 对象的方法（通过指针）

    std::cout << "Calling a function with a Cd reference argument:\n";
    Bravo1(c1);
    Bravo1(c2);

    std::cout << "Testing assignment:\n";
    Classic1 copy;
    copy = c2;
    copy.CdReport();
}

void _13_11_3()
{
    const int size = 3;
    ABC* arr[size];

    char tempLabel[50];
    int tempRating;

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter label: ";
        std::cin.getline(tempLabel, 50);
        std::cout << "Enter rating: ";
        std::cin >> tempRating;
        std::cin.ignore(); // Clear the newline from the input buffer

        std::cout << "Choose type (1: baseDMA, 2: lacksDMA): ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline from the input buffer

        switch (choice) {
            case 1:
                arr[i] = new baseDMA(tempLabel, tempRating);
                break;
            case 2:
                char tempColor[50];
                std::cout << "Enter color: ";
                std::cin.getline(tempColor, 50);
                arr[i] = new lacksDMA(tempColor, tempLabel, tempRating);
                break;
            default:
                std::cout << "Invalid choice. Defaulting to baseDMA." << std::endl;
                arr[i] = new baseDMA(tempLabel, tempRating);
                break;
        }
    }

    for (int i = 0; i < size; ++i) {
        arr[i]->View();
        std::cout << "------------------------" << std::endl;
        delete arr[i];
    }
}

void _13_11_4()
{
    VintagePort vp1("Brand1", 10, "The Noble", 2000);
    VintagePort vp2("Brand2", 8, "Old Velvet", 1995);
    VintagePort vp3(vp1);

    std::cout << "Displaying VintagePort 1:\n";
    vp1.show();

    std::cout << "\nDisplaying VintagePort 2:\n";
    vp2.show();

    std::cout << "\nDisplaying VintagePort 3 (copy of VintagePort 1):\n";
    vp3.show();

    std::cout << "\nAssigning VintagePort 2 to VintagePort 1:\n";
    vp1 = vp2;
    vp1.show();
}

class Base
{
public:
    virtual void display() const
    {
        std::cout << "Base class display()\n";
    }
};

class Derived : public Base {
public:
    void display() const override {
        // 引用基类的方法
        Base::display();

        // 在后面进行修改或添加特定于派生类的行为
        std::cout << "Derived class display()\n";
    }
};

int main()
{

    //_13_11_1();

    //_13_11_2();

    //_13_11_3();

    //_13_11_4();

    // Derived d;
    // d.display();

    return 0;
}