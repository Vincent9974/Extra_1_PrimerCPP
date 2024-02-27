#include <iostream>
#include "Televioson.h"
#include <stdexcept>
#include <cmath>
#include "myMath.h"
#include "Sales.h"

void _15_8_1()
{
    Tv myTv;
    Remote myRemote;

    myTv.settings();
    myRemote.displayMode();

    myTv.powerOn();
    myTv.settings();
    myTv.switchRemoteMode(myRemote);
    myRemote.displayMode();

    myTv.powerOn();
    myTv.settings();
    myTv.volumeUp();
    myTv.settings();
    myTv.switchRemoteMode(myRemote);
    myRemote.displayMode();
}

void _15_8_2()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
            z = gmean(x, y);
            std::cout << "Geometric mean of " << x << " and " << y << " is " << z << std::endl;
        }
        catch (const bad_hmean &bh)
        {
            std::cerr << bh.what() << std::endl;
            std::cout << "Try again.\n";
            break;
        }
        catch (const bad_gmean &bg)
        {
            std::cerr << bg.what() << std::endl;
            std::cout << "Sorry, you don't get to play any more.\n";
            break;
        }
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
}

void _15_8_3()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try
        {
            z = hmean1(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
            z = gmean1(x, y);
            std::cout << "Geometric mean of " << x << " and " << y << " is " << z << std::endl;
        }
        catch (const CustomException &ce)
        {
            std::cerr << ce.what() << std::endl;
            ce.reportValues();
            std::cout << "Try again.\n";
            continue;
        }
        std::cout << "Enter next set of numbers <q to quit>: ";
    }

    std::cout << "Bye!\n";
}

void _15_8_4()
{
    // using std::cin;
    // using std::cout;
    // using std::endl;

    // double vals1[12] = {1220, 1100, 1122, 2212, 1232, 2334,
    //                     2884, 2393, 3302, 2922, 3002, 3544};

    // double vals2[12] = {12, 11, 22, 21, 32, 34, 28, 29, 33, 29, 32, 35};

    // Sales sales1(2011, vals1, 12);
    // LabeledSales sales2("Blogstar", 2012, vals2, 12);

    // cout << "First try block:\n";
    // try {
    //     int i;
    //     cout << "Year = " << sales1.Year() << endl;
    //     for (i = 0; i < 12; ++i) {
    //         cout << sales1[i] << ' ';
    //         if (i % 6 == 5) cout << endl;
    //     }
    //     cout << "Year = " << sales2.Year() << endl;
    //     cout << "Label = " << sales2.Label() << endl;
    //     for (i = 0; i <= 12; ++i) {
    //         cout << sales2[i] << ' ';
    //         if (i % 6 == 5) cout << endl;
    //     }
    //     cout << "End of try block 1.\n";
    // } catch (Sales::bad_index &bad) {
    //     cout << bad.what();
    //     if (typeid(bad) == typeid(LabeledSales::nbad_index)) {
    //         cout << "Company: " << ((LabeledSales::nbad_index &)bad).label_val()
    //             << endl;
    //     }
    //     cout << "bad index: " << bad.bi_val() << endl;
    // }
    // cout << "\nNext try block:\n";
    // try {
    //     sales2[2] = 37.5;
    //     sales1[20] = 23345;  // 此处可能导致异常，因为超出了数组范围
    //     cout << "End of try block 2.\n";
    // } catch (Sales::bad_index &bad) {
    //     cout << bad.what();
    //     if (typeid(bad) == typeid(LabeledSales::nbad_index)) {
    //         cout << "Company: " << ((LabeledSales::nbad_index &)bad).label_val()
    //             << endl;
    //     }
    //     cout << "bad index: " << bad.bi_val() << endl;
    // }
    // cout << "done\n";
}

int main()
{
    //_15_8_1();

    //_15_8_2();

    //_15_8_3();

    //_15_8_4();
}