// sales.h
# pragma once

const int QUARTERS = 4;
class Sales {
private:
    double sales[QUARTERS];
    double average;
    double max;
    double min;

public:
    // 默认构造函数
    Sales();

    // 构造函数，接受销售数据数组
    Sales(const double arr[]);

    // 交互式构造函数
    void setSales();

    // 显示销售信息
    void showSales() const;
};