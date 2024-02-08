#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

// 1．编写一个小程序，要求用户使用一个整数指出自己的身高（
// 单位为英寸)，然后将身高转换为英尺和英寸。
// 该程序使用下划线字符来指示输入位置。
// 另外，使用一个const符号常量来表示转换因子。

void _3_7_1()
{
    const double InchesPerFoot = 12.0;  // 转换因子：1英尺 = 12英寸
    int heightInInches;

    // 提示用户输入身高
    std::cout << "请输入您的身高（单位：英寸）： ";
    std::cin >> heightInInches;

    // 计算英尺和英寸
    int feet = heightInInches / InchesPerFoot;
    int inches = heightInInches % static_cast<int>(InchesPerFoot);

    // 显示结果
    std::cout << "您的身高为：" << feet << "英尺 " << inches << "英寸" << std::endl;
}

// 2．编写一个小程序，要求以几英尺几英寸的方式输入其身高，
// 并以磅为单位输入其体重。(使用3个变量来存储这些信息。）
// 该程序报告其BMI (Body Mass Index，体重指数)。为了计算BMI，
// 该程序以英寸的方式指出用户的身高(1英尺为12英寸)，
// 并将以英寸为单位的身高转换为以米为单位的身高(1英寸=0.0254米)。
// 然后，将以磅为单位的体重转换为以千克为单位的体重(1千克=2.2磅)。
// 最后，计算相应的BMI—一体重(千克）除以身高（米）的平方。
// 用符号常量表示各种转换因子。

void _3_7_2()
{
    const double InchesPerFoot = 12.0; 
    int inche;
    float foot;
    float meterHeight;
    float poundWeight;
    float kgWeight;
    float BMI;

    cout << "Input your inches of height" << endl;
    cin >> inche;
    cout << "Input your foots of height" << endl;
    cin >> foot;
    cout << "Input your pounds of weight" << endl;
    cin >> poundWeight;

    meterHeight = static_cast<float>((InchesPerFoot*inche + foot)*0.0254); 
    kgWeight = poundWeight / 2.2;
    BMI =  kgWeight / (meterHeight * meterHeight);
    cout << "Height:" << meterHeight << "\tWeight:" << kgWeight << "\tBMI:" << BMI <<endl;

}


// 3．编写一个程序，要求用户以度、分、秒的方式输入一个纬度，
//然后以度为单位显示该纬度。1度为60分，1分等于60秒,
//请以符号常量的方式表示这些值。对于每个输入值，
//应使用一个独立的变量存储它。下面是该程序运行时的情况:
void _3_7_3()
{
    int degrees;
    int minutes;
    int seconds;
    float total;
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees:";
    cin >> degrees;
    cout << "Next, enter the minutes of arc:";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc:";
    cin >> seconds;
    float temp1 = seconds/60.0;
    float temp2 =(temp1 + minutes)/60.0;
    total = temp2 + degrees;


    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << total <<"degrees";

}


// 4．编写一个程序，要求用户以整数方式输入秒数
// （使用long或long long变量存储)，然后以天、小时、分钟和秒
// 的方式显示这段时间。使用符号常量来表示每天有多少小时、每小时
// 有多少分钟以及每分钟有多少秒。该程序的输出应与下面类似:


void _3_7_4()
{
    long seconds;
    int days;
    int hours;
    int minutes;
    int second;
    cout << "Enter the number of seconds:";
    cin >> seconds;
    days = seconds/86400;
    hours = seconds%86400/3600;
    minutes = seconds%86400%3600/60;
    second = seconds%86400%3600%60/60;

    cout << seconds << " seconds = "<< days << " days, "<< hours << " hours, "<< minutes<<" miutes, "<< second<< " seconds";
}

//5．编写一个程序，要求用户输入全球当前的人口和美国当前的人口
//（或其他国家的人口)。将这些信息存储在long long变量中，
//并让程序显示美国(或其他国家）的人口占全球人口的百分比。
//该程序的输出应与下面类似:
void _3_7_5()
{
    long long worldPopulation;
    long long usPopulation;
    double percent;
    cout << "Enter the world's population:" << endl;
    cin >> worldPopulation;
    cout << "Enter the population of the US:" << endl;
    cin >> usPopulation;
    percent = static_cast<double>(usPopulation*1.0/worldPopulation);
    percent = percent*100;
    cout << "The population of the US is " << setprecision(5) << percent << "% of the world population." << endl;

}


// 6．编写一个程序，要求用户输入驱车里程（英里）和使用汽油量(加仑)，
// 然后指出汽车耗油
// 量为一加仑的里程。如果愿意，也可以让程序要求用户以公里为单位输入
// 距离，并以升为单位输入汽油量然后指出欧洲风格的结果——
// 即每100公里的耗油量（升)。
void _3_7_6()
{    // 获取用户输入的驱车里程和使用汽油量
    double miles, gallons;
    std::cout << "请输入驱车里程（英里）：";
    std::cin >> miles;
    std::cout << "请输入使用汽油量（加仑）：";
    std::cin >> gallons;

    // 计算美国风格的耗油量（每加仑的里程）
    double milesPerGallon = miles / gallons;
    std::cout << "美国风格的耗油量为：" << milesPerGallon << " 英里/加仑" << std::endl;

    // 计算欧洲风格的耗油量（每100公里的耗油量）
    const double milesToKilometers = 1.60934;
    const double gallonsToLiters = 3.78541;
    double kilometers = miles * milesToKilometers;
    double liters = gallons * gallonsToLiters;
    double litersPer100Km = liters / kilometers * 100;
    std::cout << "欧洲风格的耗油量为：" << litersPer100Km << " 升/100公里" << std::endl;
}

int main()
{
    //_3_7_1();

    //_3_7_2();

    //_3_7_3();

    //_3_7_4();

    //_3_7_5();

    _3_7_6();

    system("pause");
    return 0;
}