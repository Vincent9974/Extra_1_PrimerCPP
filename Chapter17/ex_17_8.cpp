#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Company.h"

void test1()
{
    int userNumber;

    // Get user input
    std::cout << "Enter an integer: ";
    std::cin >> userNumber;

    // Display in decimal, octal, and hexadecimal with setw(15) and showbase
    std::cout << std::setw(15) << std::dec << std::showbase << "Decimal:";
    std::cout << std::setw(15) << userNumber;

    std::cout << std::setw(15) << std::oct << std::showbase << " Octal:";
    std::cout << std::setw(15) << userNumber;

    std::cout << std::setw(15) << std::hex << std::showbase << "Hex:";
    std::cout << std::setw(15) << userNumber;
}

void ex_17_7_7()
{
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter your hourly wages: ";
    double hourlyWages;
    std::cin >> hourlyWages;

    std::cout << "Enter number of hours worked: ";
    double hoursWorked;
    std::cin >> hoursWorked;

    // 第一种格式
    std::cout << "First format:" << std::endl;
    std::cout << std::setw(name.length() + 2) << std::right << name << ": $";
    std::cout << std::fixed << std::setprecision(1) << std::setw(6)
              << std::right << hourlyWages << ": " << hourlyWages << std::endl;

    // 第二种格式
    std::cout << "Second format:" << std::endl;

    std::cout << std::setw(name.length() + 2) << std::left
              << name;

    std::cout << ": $" << std::fixed << std::setprecision(1)
              << std::setw(5) << std::right << hourlyWages << ": "
              << hoursWorked << std::endl;
}

void ex_17_7_8()
{
    using namespace std;
    char ch;
    int ct1 = 0;

    cin >> ch;
    while (ch != 'q')
    {
        ct1++;
        cin >> ch;
    }

    int ct2 = 0;
    cin.get(ch);
    while (ch != 'q ')
    {
        ct2++;
        cin.get(ch);
    }

    cout << "ct1 = " << ct1 << " ; ct2 = " << ct2 << " in";
}

void ex_17_7_9()
{
    const int maxSize = 80;
    char buffer[maxSize];

    std::cout << "Enter a sentence: ";
    std::cin.getline(buffer, maxSize); // Read a line of input into buffer

    std::cout << "You entered: " << buffer << std::endl;

    // Ignore remaining characters in the input stream until a newline character is encountered
    std::cin.ignore(maxSize, '\n');

    // Now, let's try to read another line
    std::cout << "Enter another sentence: ";
    std::cin.getline(buffer, maxSize);

    std::cout << "You entered: " << buffer << std::endl;
}

void _17_8_1()
{
    char ch;
    int count = 0;

    std::cout << "Enter a sequence of characters (terminate with $): ";

    while (std::cin.get(ch) && ch != '$')
    {
        count++;
    }

    std::cout << "Number of characters before 'S': " << count << std::endl;

    if (ch != '$')
    {
        std::cin.putback(ch);
    }
}

void copyInputToFile(const std::string &filename)
{
    std::ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file" << filename << std::endl;
        return;
    }

    char ch;
    while (std::cin.get(ch) && ch != '$')
    {
        outputFile.put(ch);
    }

    std::cout << "Input copied to " << filename << " successfully." << std::endl;
}

void _17_8_2()
{
    std::string filename = "output.txt";
    copyInputToFile(filename);
}

void copyFile(const std::string &inputFilename,
              const std::string &outputFilename)
{
    std::ifstream inputFile(inputFilename, std::ios::binary);
    std::ofstream outputFile(outputFilename, std::ios::binary);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening input file: " << inputFilename << std::endl;
        return;
    }

    if (!outputFile.is_open())
    {
        std::cerr << "Error opening output file: " << outputFilename << std::endl;
        return;
    }

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch);
    }
    std::cout << "File copied successfully from "
              << inputFilename << " to " << outputFilename << std::endl;
}

void _17_8_3(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_filename> <output_filename>" << std::endl;
        return;
    }

    std::string inputFilename(argv[1]);
    std::string outputFilename(argv[2]);

    copyFile(inputFilename, outputFilename);
}

void _17_8_4()
{
    std::ifstream file1("./input4_1.txt");
    std::ifstream file2("./input4_2.txt");
    std::ofstream outputFile("./output4_1.txt");

    if (!file1.is_open() || !file2.is_open() || !outputFile.is_open())
    {
        std::cerr << "Error opening files" << std::endl;
        return;
    }

    std::string line1, line2;

    while (std::getline(file1, line1))
    {
        if (std::getline(file2, line2))
        {
            outputFile << line1 << " " << line2 << std::endl;
        }
        else
        {
            outputFile << line1 << std::endl;
        }
    }

    file1.close();
    file2.close();
    outputFile.close();

    std::cout << "Merged successfully and written to output.txt." << std::endl;
}

void _17_8_5()
{
    std::vector<std::string> matFriends;
    std::vector<std::string> patFriends;

    std::ifstream matFile("Mat.dat");
    std::ifstream patFile("Pat.dat");

    if(matFile.is_open())
    {
        std::string name;
        while (std::getline(matFile, name))
        {
            matFriends.push_back(name);
        }
        matFile.close();
    }
    else
    {
        std::cerr << "Error opening mat.dat" << std::endl;
        return;
    }

    std::cout << "Mat's Friend:" << std::endl;
    for(const auto& friendName : matFriends)
    {
        std::cout << friendName << std::endl;
    }

    if(patFile.is_open())
    {
        std::string name;
        while(std::getline(patFile, name))
        {
            patFriends.push_back(name);
        }
        patFile.close();
    }
    else
    {
        std::cerr << "Error opening pat.dat " << std::endl;
        return;
    }
    std::cout << "Pat's Friend:" << std::endl;
    for(const auto& friendName : patFriends)
    {
        std::cout << friendName << std::endl;
    }

    std::ofstream combinedFile("matnpat.dat");
    std::vector<std::string> combinedFriends;

    combinedFriends.reserve(matFriends.size() + patFriends.size());

    combinedFriends.insert(combinedFriends.end(),
    matFriends.begin(), matFriends.end());

    combinedFriends.insert(combinedFriends.end(),
    patFriends.begin(), patFriends.end());

    std::sort(combinedFriends.begin(), combinedFriends.end());
    auto last = std::unique(combinedFriends.begin(), combinedFriends.end());
    combinedFriends.erase(last, combinedFriends.end());

    std::ofstream mergedFile("matnpat.dat");
    for(const auto& friendName: combinedFriends)
    {
        mergedFile << friendName << std::endl;
    }

    std::cout << "mergedFile's Friend:" << std::endl;
    for(const auto& friendName : combinedFriends)
    {
        std::cout << friendName << std::endl;
    }
}

void _17_8_6()
{
    // const int MAX = 10;
    // employee* pc[MAX];
    // int index = 0;

    // char ch;
    
}

using namespace std;

void ShowStr(const string &s)
{
    cout << s << endl;
}

class Store {
private:
    ofstream &ofs; // Reference to ofstream object

public:
    // Constructor that takes ofstream object as a parameter
    Store(ofstream &os) : ofs(os) {}

    // Overloaded function call operator
    void operator()(const string &s) const {
        // Store length of string
        size_t len = s.length();
        ofs.write(reinterpret_cast<const char*>(&len), sizeof(size_t));

        // Store characters
        ofs.write(s.data(), len);
    }
};

// Function to retrieve strings from a file
void GetStrs(ifstream &ifs) {
    size_t len;
    while (ifs.read(reinterpret_cast<char*>(&len), sizeof(size_t))) {
        // Read characters
        string temp;
        temp.resize(len);
        ifs.read(&temp[0], len);

        // Display the string
        ShowStr(temp);
    }
}

void _17_8_7()
{
    // acquire strings
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);

    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    if (!fout.is_open()) {
        cerr << "Could not open file for output.\n";
        exit(EXIT_FAILURE);
    }

    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }

    cout << "\nHere are the strings read from the file:\n";
    GetStrs(fin);
}

int main(int argc, char *argv[])
{

    // test1();

    // ex_17_7_7();

    // ex_17_7_8();

    //_17_8_1();

    //_17_8_2();

    //_17_8_3(argc, argv); // 控制台输入"./ex_17_8 input.txt output.txt"

    //_17_8_4();

    //_17_8_5();

    //_17_8_6();

    _17_8_7();

    return 0;
}
