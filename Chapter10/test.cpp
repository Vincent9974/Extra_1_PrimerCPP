#include <iostream>

using namespace std;


class MyClass {
public:
    void printAddress() {
        std::cout << "Address of the current object: " << this << std::endl;
    }
};

class Point {
public:
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    Point& add(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
};

// int main() {

//     // MyClass obj;
//     // obj.printAddress();

//     Point p1(1, 2);
//     Point p2(3, 4);
//     p1.add(p2);
//     // p1 现在变为 (4, 6)


//     return 0;
// }
