#include "sales.h"
#include <iostream>


void SALES::setSales(Sales &s, const double ar[], int n)
{
    n = std::min(n, QUARTERS);

    // Copy the lesser of 4 or n items from ar to the sales member of s
    std::copy(ar, ar + n, s.sales);

    // Compute and store the average, maximum, and minimum values
    s.average = 0.0;
    s.max = s.sales[0];
    s.min = s.sales[0];

    for (int i = 0; i < n; ++i) {
        s.average += s.sales[i];
        if (s.sales[i] > s.max) {
            s.max = s.sales[i];
        }
        if (s.sales[i] < s.min) {
            s.min = s.sales[i];
        }
    }

    // Calculate the average
    s.average /= n;

    // Remaining elements of sales, if any, set to 0
    for (int i = n; i < QUARTERS; ++i) {
        s.sales[i] = 0.0;
    }

}


void SALES::setSales(Sales &s) {
    // Gathers sales for 4 quarters interactively, stores them in the sales member of s,
    // and computes and stores the average, maximum, and minimum values
    for (int i = 0; i < QUARTERS; ++i) {
        std::cout << "Enter sales for quarter " << i + 1 << ": ";
        std::cin >> s.sales[i];
    }

    // Compute and store the average, maximum, and minimum values
    s.average = s.sales[0];
    s.max = s.sales[0];
    s.min = s.sales[0];

    for (int i = 1; i < QUARTERS; ++i) {
        s.average += s.sales[i];
        if (s.sales[i] > s.max) {
            s.max = s.sales[i];
        }
        if (s.sales[i] < s.min) {
            s.min = s.sales[i];
        }
    }

    // Calculate the average
    s.average /= QUARTERS;
}

void SALES::showSales(const Sales &s) {
    // Display all information in structure s
    std::cout << "Sales: ";
    for (int i = 0; i < QUARTERS; ++i) {
        std::cout << s.sales[i] << " ";
    }
    std::cout << "\nAverage: " << s.average
                << "\nMax: " << s.max
                << "\nMin: " << s.min << std::endl;
}