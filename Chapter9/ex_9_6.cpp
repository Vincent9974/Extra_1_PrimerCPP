#include <iostream>
#include "golf.h"
#include <cstring>
#include "sales.h"

using namespace std;

void _9_5_1()
{
    using namespace std;
    const int MaxPlayers = 3;
    golf players[MaxPlayers];
    int i;
    for ( i = 0; i < MaxPlayers; i++) {
        setgolf(players[i]);
    }

    cout << "\nGolf Players:\n";
    for (int j = 0; j < i; j++) {
        showgolf(players[j]);
    }
}

const int Arsize = 10;

// function prototype
void strcount(const std::string& str) {
    using namespace std;
    static int total = 0; // static local variable
    int count = 0;        // automatic local variable

    cout << "\"" << str << "\" contains ";
    count = str.size();
    total += count;
    
    cout << count << " characters\n";
    cout << total << " characters total\n";
}

void _9_5_2() {
    using namespace std;

    string input;
    char next;

    cout << "Enter a line:\n";
    getline(cin, input);

    while (!input.empty()) {
        cin.get(next);
        while (next != '\n') {
            cout << "String didn't fit!\n";
            cin.get(next);
        }

        // dispose of remainder
        strcount(input);

        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }

    cout << "Bye\n";
}


struct chaff
{
    char dross[20];
    int slag;
};

void _9_5_3()
{
    const int arraySize =2;
    char buffer[sizeof(chaff) * arraySize];

    chaff* chaArr = new (buffer) chaff[arraySize];

    // 给结构的成员赋值
    for (int i = 0; i < arraySize; ++i) {
        strcpy(chaArr[i].dross, "Dross Value"); // 通过 strcpy_s 给 char 数组赋值
        chaArr[i].slag = i + 1; // 给 int 成员赋值
    }

    // 显示内容
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Element " << i << ": Dross = " << chaArr[i].dross << ", Slag = " << chaArr[i].slag << std::endl;
    }

    for(int i = 0; i < arraySize; ++i)
    {
        chaArr[i].~chaff();
    }

    //delete[] chaArr;
}

void _9_5_4()
{
    using namespace SALES;

    Sales s1,s2;

    setSales(s1);

    // Use setSales() non-interactive version for another structure
    double arr[] = {3000.0, 4500.0, 6000.0, 7500.0};
    setSales(s2, arr, 4);

    // Use showSales() to display both structures
    showSales(s1);
    showSales(s2);

}


int main()
{

    //_9_5_1();

    //_9_5_2();

    //_9_5_3();

    _9_5_4();

    return 0;
}