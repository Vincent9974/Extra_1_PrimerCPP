#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

float fAvg(int num1, int num2);
void _7_13_1()
{
    while (1)
    {
        int number1;
        int number2;
        cout << "Enter 2 numbers:" << endl;
        cin >> number1;
        cin >> number2;
        if (number1 == 0 || number2 == 0)
        {
            break;
        }
        cout << "调和平均数:" << fAvg(number1, number2) << endl;
        ;
    }
}

int *getGolfScore(int &arrSize);
void showScore(int arr[], int arrSize);
float getAvg(int arr[], int arrSize);

void _7_13_2()
{
    int arrSize = 0;
    int *arr = getGolfScore(arrSize);
    showScore(arr, arrSize);
    cout << getAvg(arr, arrSize) << endl;
}

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

// 按值传递打印结构体
void printBox_a(struct box b)
{
    cout << b.maker << endl;
    cout << b.height << endl;
    cout << b.width << endl;
    cout << b.length << endl;
    cout << b.volume << endl;
}

// 设置体积
void setVolume_b(struct box *b)
{
    b->volume = b->height * b->width * b->length;
}

void _7_13_3()
{
    box b = {"box", 1, 2, 3};
    setVolume_b(&b);
    printBox_a(b);
}

struct LotteryTicket
{
    int fieldNumbers;         // 域号码
    int selectedFieldNumbers; // 选择的域号码数量
    int specialNumber;        // 特选号码
};

// 计算头奖几率的函数
double calculateJackpotProbability(const struct LotteryTicket &ticket)
{
    // 模拟从域号码中正确选择所有号码的几率
    double fieldProbability = 1.0;
    for (int i = 0; i < ticket.selectedFieldNumbers; ++i)
    {
        fieldProbability *= static_cast<double>(ticket.fieldNumbers - i) / (i + 1);
    }

    // 模拟从特选号码中正确选择号码的几率
    double specialProbability = 1.0 / ticket.fieldNumbers;

    // 计算中头奖的几率（域号码几率 * 特选号码几率）
    double jackpotProbability = fieldProbability * specialProbability;

    return jackpotProbability;
}

void _7_13_4()
{

    // 创建一个彩票对象
    LotteryTicket myTicket = {47, 5, 1};

    // 调用计算头奖几率的函数
    double probability = calculateJackpotProbability(myTicket);

    // 输出计算结果
    std::cout << "Jackpot Probability: " << probability << std::endl;
}

int frac(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * frac(n - 1);
}

void _7_13_5()
{
    while (1)
    {
        int number;
        cout << "Enter the number to frac. exie with -number." << endl;
        cin >> number;
        if (number < 0)
        {
            return;
        }
        else
        {
            cout << number << "!= " << frac(number) << endl;
        }
    }
}

int Fill_array(double arr[], int size)
{
    int count = 0;
    cout << "Please enter the double number. end with -" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Please enter the value " << i << endl;
        if (cin >> arr[i])
        {
            count++;
        }
        else if (cin.fail())
        {
            break;
        }
    }
    return count;
}

void Show_array(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

void Reverse_array(double arr[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }
}

void _7_13_6()
{
    double arr[5];
    int arrSize = sizeof(arr);
    int fillNumber = Fill_array(arr, arrSize);
    cout << fillNumber << endl;
    cout << "==" << endl;
    Show_array(arr, fillNumber);
    cout << "==" << endl;
    Reverse_array(arr, fillNumber);
}

// 填充数组的函数，返回指向最后被填充位置的指针
double *fill_array(double *begin, double *end)
{
    double *current = begin;
    cout << "Enter double numbers. To stop, enter a non-numeric value." << endl;

    while (current != end && cin >> *current)
    {
        ++current;
    }

    return current; // 返回指向最后被填充位置的指针
}

// 显示数组内容的函数
void show_array(const double *begin, const double *end)
{
    for (const double *current = begin; current != end; ++current)
    {
        cout << *current << " ";
    }
    cout << endl;
}

// 反转数组的函数
void reverse_array(double *begin, double *end)
{
    while (begin < end)
    {
        --end;
        swap(*begin, *end);
        ++begin;
    }
}

void _7_13_7()
{

    const int arrSize = 5;
    double arr[arrSize];

    double *endPointer = fill_array(arr, arr + arrSize);

    // 显示填充后的数组内容
    show_array(arr, endPointer);

    // 反转数组
    reverse_array(arr, endPointer);

    // 显示反转后的数组内容
    show_array(arr, endPointer);
}

const int QUARTERS = 4;
const char *seasons[] = {"spring", "summer", "fail", "winter"};
struct QuarterExpenses
{
    double expenses[QUARTERS];
};

void fill_expenses(double expenses[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter expenses for " << seasons[i] << ": ";
        std::cin >> expenses[i];
    }
}

void show_expenses(const double expenses[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Expenses for " << seasons[i] << ": " << expenses[i] << std::endl;
    }
}

void _7_13_8()
{
    double expenses[QUARTERS];
    fill_expenses(expenses, QUARTERS);
    show_expenses(expenses, QUARTERS);
}

struct student
{
    char fullname[30];
    char hobby[30];
    int ooplevel;
};

int getinfo(student pa[], int n)
{
    int count = 0;
    cout << "Enter the information:" << endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "学生 #" << (i + 1) << " 姓名（输入空行以停止）：";
        std::cin.getline(pa[i].fullname, sizeof(pa[i].fullname));

        std::cout << "输入 " << pa[i].fullname << " 的年龄：";
        std::cin >> pa[i].fullname;

        // 检查是否输入空行以停止
        if (pa[i].fullname[0] == '\0')
        {
            break;
        }

        std::cout << "输入 " << pa[i].fullname << " 的爱好：";
        std::cin.getline(pa[i].hobby, sizeof(pa[i].hobby));

        std::cout << "输入 " << pa[i].fullname << " 的OOP级别：";
        std::cin >> pa[i].ooplevel;

        ++count;
    }

    return count;
}


// display1() 函数：以值传递方式显示学生结构的内容
void display1(student st) {
    std::cout << "姓名: " << st.fullname << std::endl;
    std::cout << "爱好: " << st.hobby << std::endl;
    std::cout << "OOP级别: " << st.ooplevel << std::endl;
}

// display2() 函数：以指针传递方式显示学生结构的内容
void display2(const student *ps) {
    std::cout << "姓名: " << ps->fullname << std::endl;
    std::cout << "爱好: " << ps->hobby << std::endl;
    std::cout << "OOP级别: " << ps->ooplevel << std::endl;
}

// display3() 函数：以数组和元素个数传递方式显示学生结构的内容
void display3(const student pa[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "学生 #" << (i + 1) << " 的信息：" << std::endl;
        std::cout << "姓名: " << pa[i].fullname << std::endl;
        std::cout << "爱好: " << pa[i].hobby << std::endl;
        std::cout << "OOP级别: " << pa[i].ooplevel << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
void _7_13_9()
{
    const int maxSize = 3; // 为了演示，设置为 3
    student students[maxSize];

    // 获取学生信息
    int actualSize = getinfo(students, maxSize);

    std::cout << "输入的学生数量：" << actualSize << std::endl;

    // 使用 display1() 以值传递方式显示第一个学生的信息
    std::cout << "使用 display1() 显示第一个学生的信息：" << std::endl;
    display1(students[0]);

    // 使用 display2() 以指针传递方式显示第二个学生的信息
    std::cout << "使用 display2() 显示第二个学生的信息：" << std::endl;
    display2(&students[1]);

    // 使用 display3() 以数组和元素个数传递方式显示所有学生的信息
    std::cout << "使用 display3() 显示所有学生的信息：" << std::endl;
    display3(students, actualSize);
}

typedef double (*ArithmeticFunction) (double, double);

double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}



double multiply(double x, double y) {
    return x * y;
}

// 函数指针数组
double (*pf[3])(double, double) = {add, subtract, multiply};
// calculate() 函数，接受两个 double 值和一个函数指针，并返回计算结果
double calculate(double x, double y, double (*operation)(double, double)) {
    return operation(x, y);
}

void _7_13_10()
{
    double num1, num2;
    int choice;

    // 用户输入数字和选择
    do {
        std::cout << "输入两个数字：" << std::endl;
        std::cin >> num1 >> num2;

        std::cout << "选择操作：" << std::endl;
        std::cout << "1. 相加\n2. 相减\n3. 相乘\n4. 退出\n";
        std::cin >> choice;

        // 检查用户的选择
        if (choice >= 1 && choice <= 3) {
            double result = calculate(num1, num2, pf[choice - 1]);
            std::cout << "计算结果: " << result << std::endl;
        } else if (choice != 4) {
            std::cout << "无效的选择，请重新输入。\n";
        }

    } while (choice != 4);

}

int main()
{

    // _7_13_1();

    //_7_13_2();

    //_7_13_3();

    //_7_13_4();

    //_7_13_5();

    //_7_13_6();

    //_7_13_7();

    //_7_13_8();

    //_7_13_9();

    _7_13_10();

    return 0;
}

float fAvg(int x, int y)
{
    return (2.0 * x * y) / (x + y);
}

int *getGolfScore(int &arrSize)
{
    const int size = 10;
    int *golfScore = new int[size];

    for (int i = 0; i < size; i++)
    {
        int score;
        cout << "Please enter the score. (end with -1)" << endl;
        cin >> score;
        if (score == -1)
        {
            break;
        }
        else
        {
            golfScore[i] = score;
            arrSize += 1;
        }
    }

    return golfScore;
}

void showScore(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }
}

float getAvg(int arr[], int arrSize)
{
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    return sum / arrSize;
}
