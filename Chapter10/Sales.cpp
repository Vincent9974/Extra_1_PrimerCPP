#include "sales.h"
#include <iostream>


// 实现默认构造函数
Sales::Sales() {
    for (int i = 0; i < QUARTERS; ++i) {
        sales[i] = 0.0;
    }
    average = 0.0;
    max = 0.0;
    min = 0.0;
}

// 实现构造函数，接受销售数据数组
Sales::Sales(const double arr[]) {
    for (int i = 0; i < QUARTERS; ++i) {
        sales[i] = arr[i];
    }

    // 计算平均值、最大值和最小值
    double total = 0.0;
    max = min = arr[0];

    for (int i = 0; i < QUARTERS; ++i) {
        total += arr[i];

        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    average = total / QUARTERS;
}

// 实现交互式构造函数
void Sales::setSales() {
    std::cout << "Enter sales data for each quarter:\n";
    for (int i = 0; i < QUARTERS; ++i) {
        std::cout << "Quarter " << (i + 1) << ": ";
        std::cin >> sales[i];
    }

    // 计算平均值、最大值和最小值
    double total = 0.0;
    max = min = sales[0];

    for (int i = 0; i < QUARTERS; ++i) {
        total += sales[i];

        if (sales[i] > max) {
            max = sales[i];
        }

        if (sales[i] < min) {
            min = sales[i];
        }
    }

    average = total / QUARTERS;
}

// 实现显示销售信息的方法
void Sales::showSales() const {
    std::cout << "Sales data:\n";
    for (int i = 0; i < QUARTERS; ++i) {
        std::cout << "Quarter " << (i + 1) << ": " << sales[i] << std::endl;
    }

    std::cout << "Average: " << average << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
}

