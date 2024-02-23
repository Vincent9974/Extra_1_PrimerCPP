#include <iostream>



class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;

public:
    Stonewt(double lbs);        // 以磅为单位的构造函数
    Stonewt(int stn, double lbs); // 以英石和磅为单位的构造函数
    Stonewt();                  // 默认构造函数
    ~Stonewt();

    
    void show_lbs() const;      // 以磅为单位显示
    void show_stn() const;      // 以英石和磅为单位显示

    Stonewt operator*(double n) const;

};

// int main()
// {

//     Stonewt weight(10, 8);
//     double factor =2.0;

//     std::cout << "原始重量:";

//     Stonewt result = weight * factor;

//     std::cout << "乘以 " << factor << " 后的重量：";
//     result.show_stn();


//     return 0;
// }

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;  // 整数部分为英石
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);  // 浮点数部分为磅
    pounds = lbs;
}


Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}


Stonewt::~Stonewt() {
}

void Stonewt::show_lbs() const {
    std::cout << pounds << " 磅\n";
}

void Stonewt::show_stn() const {
    std::cout << stone << " 英石, " << pds_left << " 磅\n";
}

Stonewt Stonewt::operator*(double n) const
{
    double new_pounds = this->pounds * n;
    return Stonewt(new_pounds);
}






