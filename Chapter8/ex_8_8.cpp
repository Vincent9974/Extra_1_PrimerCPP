#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void printString(const char *str, int n)
{
    static int uses = 0;

    int lim = ++uses;
    if (n == 0)
        lim = 1;
    for (int i = 0; i < lim; i++)
    {
        cout << str;
    }
}

void _8_8_1()
{
    char str[] = "string!";
    
    printString(str,0);
    for(int i = 0; i < 3; i++)
    {
        cout << i << " = i\n";
        printString(str, i);
    }
    cout << "Done";
}

struct CandyBar
{
    char brand[50];
    float weight;
    int calo;
};

void setCandyBar(CandyBar& cb, const char* charPtr="Millennium",
                    double weight=2.85, int calo=350)
{
    strcpy(cb.brand, charPtr);
    cb.weight = weight;
    cb.calo = calo;
}

void showCandyBar(const CandyBar& cb)
{
    cout << cb.brand << endl;
    cout << cb.weight << endl;
    cout << cb.calo << endl;
}

void _8_8_2()
{
    CandyBar myCandyBar;
    CandyBar myCandyBar1;
    
    const char* brandname = "Kitkat";
    setCandyBar(myCandyBar, brandname, 2.5, 300);

    showCandyBar(myCandyBar);
}

void upperString(string& str)
{
    for(auto it = str.begin();it!=str.end();it++)
    {
        *it = toupper(*it);
    }
    for(auto it = str.begin();it!=str.end();it++)
    {
        cout << *it;
    }
    cout << endl;
}

void _8_8_3()
{
    while(1)
    {
        cout << "Enter a string (q to quit):" << endl;
        string input;
        getline(cin,input);
        if(input == "q")
        {
            cout << "Bye.";
            break;
        }
        upperString(input);
    }
}

struct stringy
{
    char* str;
    int ct;
};

void set(stringy& beany,  char* testing)
{
    beany.str = new char[strlen(testing)+1];
    strcpy(beany.str, testing);
    beany.ct = strlen(testing);
}

void show(stringy beany)
{
    cout << beany.ct << endl;
    cout << beany.str << endl;
}

void show(stringy beany, int n)
{
    for(int i=0; i< n; ++i)
    {
        cout << beany.ct << endl;
        cout << beany.str << endl;
    }
}

void _8_8_4()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);

    show(beany);
    show(beany,2);

    cout << "==" << endl;
    testing[0] = 'D';
    testing[1] = 'U';
}

template <typename T>
T max5(T arr[])
{
    T max = arr[0];
    for(int i = 0; i < sizeof(arr);i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

void _8_8_5()
{
    int arrInt[5] = {1,2,3,4,5};
    float arrFloat[5] = {1.1,2.2,3.3,4.4,5.5};

    cout << max5(arrInt) << endl;
    cout << max5(arrFloat) << endl;
}


template <typename T>
T maxn(T arr[], int size) {
    T maxElement = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    return maxElement;
}

template<>
const char* maxn(const char* arr[], int size)
{
    const char* maxLengthStr = arr[0];

    for(int i = 0; i < size; i++)
    {
        if(strlen(arr[i]) > strlen(maxLengthStr))
        {
            maxLengthStr = arr[i];
        }
    }

    return maxLengthStr;
}

void _8_8_6()
{
    // 测试包含6个int元素的数组
    int intArray[] = {1, 5, 3, 8, 2, 7};
    std::cout << "Max element in intArray: " << maxn(intArray, 6) << std::endl;

    // 测试包含4个double元素的数组
    double doubleArray[] = {2.5, 1.1, 4.3, 3.0};
    std::cout << "Max element in doubleArray: " << maxn(doubleArray, 4) << std::endl;

    // 测试包含5个字符串指针的数组
    const char* strArray[] = {"apple", "orange", "banana", "grape", "kiwi"};
    const char* maxLengthStr = maxn(strArray, 5);
    std::cout << "Longest string: " << maxLengthStr << std::endl;

}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template <typename T>
T SumArray(T *arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]->amount;
    }
    return sum;
}

struct debts
{
    char name[50];
    double amount;
};

void _8_8_7()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}};

    double total1 = SumArray(things, 6);
    cout << "Total number of Mr. E's things: " << total1 << endl;

}

int main()
{

    //_8_8_1();

    //_8_8_2();

    //_8_8_3();
    
    //_8_8_4();

    //_8_8_5();

    //_8_8_6();

    _8_8_7();

    return 0;
}