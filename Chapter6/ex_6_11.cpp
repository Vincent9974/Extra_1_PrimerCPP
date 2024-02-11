#include <iostream>
#include <cctype>
#include <array>
#include <vector>
#include <fstream>


using namespace std;

void _6_11_1()
{
    char ch;
    cout << "Enter the string, stop with entering @" << endl;
    while (cin.get(ch) && ch != '@')
    {
        if (islower(ch))
        {
            ch = ch + 'A' - 'a';
        }
        cout << ch;
    }
}

void _6_11_2()
{
    const int MaxSize = 10;
    array<double, MaxSize> donations;
    double numbers;

    // 从用户输入中获取数组元素
    for (int i = 0; i < donations.size(); ++i)
    {
        std::cout << "Enter donation #" << (i + 1) << ": ";
        std::cin >> donations[i];
    }
    double sum = 0.0;
    for (double donation : donations)
    {
        sum += donation;
    }
    double avg = sum / donations.size();

    cout << "Avg:" << avg << endl;

    int aboveAvgCount = 0;
    for (double donation : donations)
    {
        if (donation > avg)
        {
            aboveAvgCount++;
        }
    }
    cout << "aboveAvgCount:" << aboveAvgCount << endl;
}

void _6_11_3()
{
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore\t p) pianist" << endl;
    cout << "t) tree     \t g) game   " << endl;

    char ch;
    if (cin.get(ch) && isalpha(ch))
    {
        switch (ch)
        {
        case 'c':
            cout << "A maple is a carnivore";
            break;
        case 'p':
            cout << "A maple is a pianist";
            break;
        case 't':
            cout << "A maple is a tree";
            break;
        case 'g':
            cout << "A maple is a game";
            break;
        default:
            cout << "Please enter a c, p, t, or g:" << endl;
            break;
        }
    }
    else
    {
        cout << "please enter the alpha!" << endl;
        _6_11_3();
    }
}

const int strsize = 100;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

void _6_11_4()
{
    const int bopSize = 5;
    vector<bop> bops;
    bop bops0 = {"a", "aa", "aaa", 1};
    bop bops1 = {"b", "bb", "bbb", 1};
    bop bops2 = {"c", "cc", "ccc", 2};
    bop bops3 = {"d", "dd", "ddd", 2};
    bop bops4 = {"e", "ee", "eee", 2};

    bops.push_back(bops0);
    bops.push_back(bops1);
    bops.push_back(bops2);
    bops.push_back(bops3);
    bops.push_back(bops4);

    cout << "a. display by name    \t b.display by title" << endl;
    cout << "c. display by bopname \t d.display by preference" << endl;
    cout << "q. quit" << endl;

    char ch;
    while (1)
    {
    start:
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 'a':
            for (bop b : bops)
            {
                cout << b.fullname << endl;
            }
            break;
        case 'b':
            for (bop b : bops)
            {
                cout << b.title << endl;
            }
            break;
        case 'c':
            for (bop b : bops)
            {
                cout << b.bopname << endl;
            }
            break;
        case 'd':
            for (bop b : bops)
                if (b.preference == 1)
                    cout << b.title << endl;
            break;
        case 'q':
            cout << "Bye!" << endl;
            return;
        default:
            break;
        }
        goto start;
    }
}

void _6_11_5()
{
    while (1)
    {
        cout << "Enter the salary:" << endl;
        int salary;
        cin >> salary;
        if (cin.fail() || salary < 0)
        {
            break;
        }
        else if (salary <= 5000)
        {
            cout << "不收税" << endl;
        }
        else if (salary > 5000 && salary <= 15000)
        {
            cout << "收税:" << (salary - 5000) * 0.1 << endl;
        }
        else if (salary > 15000 && salary <= 35000)
        {
            cout << "收税:" << (salary - 15000) * 0.15 + 1000 << endl;
        }
        else if (salary > 35000)
        {
            cout << "收税:" << (salary - 35000) * 0.2 + 1000 + 3000 << endl;
        }
    }
}

struct donator
{
    string name;
    double money;
};

void _6_11_6()
{
    vector<donator> donators;
    cout << "Enter the donators, end with EOF" << endl;

    while (1)
    {
        donator newDonator;

        cout << "Enter the name of donator" << endl;
        getline(cin, newDonator.name);
        if (newDonator.name == "q")
        {
            break;
        }

        cout << "Enter the money of donation" << endl;
        cin >> newDonator.money;
        cin.ignore();

        donators.push_back(newDonator);
    }

    vector<donator> grandPatron;
    vector<donator> smallPatron;
    for (donator d : donators)
    {
        if (d.money > 10000)
        {
            grandPatron.push_back(d);
        }
        else if (d.money <= 10000)
        {
            smallPatron.push_back(d);
        }
    }

    // display grandPatron
    cout << "grandPatrons:" << endl;
    for (donator d : grandPatron)
    {
        cout << d.name << "\t"
             << static_cast<int>(d.money) << endl;
    }

    cout << "smallPatrons:" << endl;
    for (donator d : smallPatron)
    {
        cout << d.name << "\t"
             << static_cast<int>(d.money) << endl;
    }
}

void _6_11_7()
{
    string word;
    cout << "enter the word: (q to quit):" << endl;
    vector<string> words;
    while (1)
    {
        cin >> word;
        if (word == "q")
        {
            break;
        }
        words.push_back(word);
    }
    int vowelCount = 0;
    int consnantCount = 0;
    for (string w : words)
    {
        if(isalpha(w[0]))
        {
            switch (w[0])
            {
                case 'a':
                    vowelCount++;
                    break;
                case 'e':
                    vowelCount++;
                    break;
                case 'i':
                    vowelCount++;
                    break;
                case 'o':
                    vowelCount++;
                    break;
                case 'u':
                    vowelCount++;
                    break;
                default:
                    consnantCount++;
                    break;
            }
        }
    }
    cout << vowelCount <<" words begining with vowels" << endl;
    cout << consnantCount <<" words begining with consnant" << endl;
    cout << words.size()-vowelCount-consnantCount <<" others" << endl;
}

void _6_11_8()
{
    ifstream file("example.txt");
    if(!file.is_open())
    {
        cout << "fail to open." << endl;
    }

    char ch;
    int charCount=0;

    while(file.get(ch))
    {
        charCount++;
    }

    file.close();
    cout << "Number of charCount:" << charCount << endl;
}

void _6_11_9()
{

}

int main()
{

    //_6_11_1();

    //_6_11_2();

    //_6_11_3();

    //_6_11_4();

    //_6_11_5();

    //_6_11_6();

    //_6_11_7();

    _6_11_8();

    //_6_11_9();

    return 0;
}
