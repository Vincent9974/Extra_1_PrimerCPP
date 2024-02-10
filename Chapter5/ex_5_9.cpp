#include <iostream>
#include <array>
#include <vector>
#include <cstring>

using namespace std;

void ex_5_9_1()
{
    int floor;
    int ceil;
    int sum = 0;
    cout << "Enter the corrdior:" << endl;
    cin >> floor;
    cin >> ceil;

    for (int i = floor; i <= ceil; i++)
    {
        sum += i;
    }
    cout << "Sum = " << sum << endl;
}

void ex_5_9_2()
{
    array<long double, 100> factorials;
    factorials[0] = factorials[1] = 1;

    for (int i = 2; i <= 100; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }
}

void ex_5_9_3()
{
    int number;
    int sum = 0;

    cout << "Enter the number, end with entering 0" << endl;

    do
    {
        cin >> number;
        sum = number + sum;
        cout << "Sum:" << sum << endl;
    } while (number != 0);
}

void ex_5_9_4()
{
    float D_interest = 0.1;
    float C_interest = 0.05;

    float D_sum = 100;
    float C_sum = 100;

    int year = 0;
    do
    {
        D_sum = D_sum + 10;
        C_sum = C_sum + C_sum * C_interest;
        year++;
    } while (C_sum < D_sum);

    cout << "year:" << year << endl;
    cout << "Cleo:" << C_sum << endl;
    cout << "Daphne:" << D_sum << endl;
}

void ex_5_9_5()
{
    array<int, 12> monthSales;
    int yearSales = 0;

    for (int i = 1; i <= 12; i++)
    {
        cout << "Enter " << i << " th month sales:" << endl;
        cin >> monthSales[i - 1];
        yearSales = yearSales + monthSales[i - 1];
    }

    cout << "yearSales: " << yearSales << endl;
}

void ex_5_9_6()
{
    array<array<int, 12>, 3> monthSalesInThreeYears;
    int threeYearSales = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 1; i <= 12; i++)
        {
            cout << "Enter " << j + 1 << "year " << i << " th month sales:" << endl;
            cin >> monthSalesInThreeYears[j][i - 1];
            threeYearSales = threeYearSales + monthSalesInThreeYears[j][i - 1];
        }
    }

    cout << "threeYearSales:" << threeYearSales << endl;
}

struct car
{
    string brand;
    int year;
};

void ex_5_9_7()
{
    int carNumber;
    cout << "How many cars do you wish to catalog?" << endl;
    cin >> carNumber;
    vector<car> v1;

    for(int i =0; i< carNumber; i++)
    {
        car* c = new car;
        cout << "please enter the make:" << endl;
        cin >> c->brand;
        cout << "please enter the year made:" << endl;
        cin >> c->year;
        v1.push_back(*c);
        delete c;
    }

    cout << "Here is your collection:" << endl;
    for(int i =0; i< v1.size();i++)
    {
        cout << v1[i].year << " " << v1[i].brand << endl;
    }
}

void ex_5_9_8()
{
    const int MAX_SIZE = 100;
    char words[MAX_SIZE];
    int wordCount = 0;
    cout << "Enter words (to stop, type the word done):" << endl;
    while(cin >> words && strcmp(words,"done"))
    {
        wordCount ++;
    }
    cout << "You entered a total of " << wordCount << " words.";
}

void ex_5_9_9()
{
    string words;
    int wordCount = 0;
    cout << "Enter words (to stop, type the word done):" << endl;
    while(cin >> words && words != "done")
    {
        wordCount ++;
    }
    cout << "You entered a total of " << wordCount << " words.";
}

void ex_5_9_10()
{
    int numbers;
    cout << "Enter number of rows:";
    cin >> numbers;

    for(int i=1;i<=numbers;i++)
    {
        for(int j=1;j<=numbers-i;j++)
        {
            cout<<".";
        }
        for(int k=1;k<=i;k++)
        {
            cout<< "*";
        }
        cout << "\n";
    }
}

int main()
{
    // ex_5_9_1();

    // ex_5_9_2();

    // ex_5_9_3();

    // ex_5_9_4();

    // ex_5_9_5();

    // ex_5_9_6();

    // ex_5_9_7();

    // ex_5_9_8();

    //ex_5_9_9();

    ex_5_9_10();

    return 0;
}