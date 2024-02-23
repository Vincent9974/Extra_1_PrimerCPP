#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "myTime.h"
#include "walker.h"
#include "vector.h"
#include "complex0.h"



using namespace std;

// void _11_9_1()
// {
// }

void _11_9_2()
{
    using namespace std;
    using namespace VECTOR;

    Vector v1(3, 4);
    Vector v2(5, 6, Vector::POL);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector v3 = v1 + v2;
    cout << "v1 + v2: " << v3 << endl;

    Vector v4 = 2 * v1;
    cout << "2 * v1: " << v4 << endl;

    v1.polar_mode();
    cout << "v1 in polar mode: " << v1 << endl;

}

void _11_9_3()
{
}

void _11_9_4()
{
    Time t1(2, 30);
    Time t2(1, 45);

    // Test addition operator
    Time sum = t1 + t2;
    std::cout << "Sum of t1 and t2: " << sum << std::endl;

    // Test subtraction operator
    Time diff = t1 - t2;
    std::cout << "Difference between t1 and t2: " << diff << std::endl;

    // Test multiplication operator
    Time scaledTime = 1.5 * t1;
    std::cout << "Scaled time (1.5 * t1): " << scaledTime << std::endl;
}

void _11_9_7()
{
    Complex a(3.0, 4.0); // initialize to (3,4i)
    Complex c;

    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c) {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << c * 2.0 << '\n';

        cout << "Enter a complex number (q to quit):\n";
    }

    cout << "Done!\n";
}


int main()
{
    //_11_9_1();

    //_11_9_2();

    //_11_9_4();

    _11_9_7();

    return 0;
}