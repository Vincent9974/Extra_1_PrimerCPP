// #include <iostream>

// using namespace std;

// void other();

// namespace n1 {
//     int x = 1;
// }

// namespace n2 {
//     int x = 2;
//     int main() {
//         using namespace n1;
//         cout << x << endl;
//         {
//             int x = 4;
//             cout << x << ", " << n1::x << ", " << n2::x << endl;
//         }
//         using n2::x;
//         cout << x << endl;
//         other();
//         return 0;
//     }
// }

// int main() {
//     using namespace n1;
//     cout << x << endl;
//     {
//         int x = 4;
//         cout << x << ", " << n1::x << ", " << n2::x << endl;
//         cout << x << endl;
//         other();
//         return 0;
//     }
// }

// void other() {
//     using namespace n2;
//     cout << x << endl;
//     int x = 4;
//     cout << x << ", " << n1::x << ", " << n2::x << endl;
// }



// // // 使用 volatile 声明一个全局变量
// // volatile int flag = 0;

// // // 模拟一个中断处理函数
// // void interruptHandler() {
// //     // 假设在中断中改变了 flag 的值
// //     flag = 1;
// // }



// // int main() {
// //     double x;
// //     std::cout << "Enter value: ";
// //     while(! (std::cin >> x))
// //     {
// //         std::cout << "Bad input. Please enter a number: ";
// //         std::cin.clear();
// //         while(std::cin.get() !='\n')
// //         {
// //             continue;
// //         }
// //         std::cout << "Value = " << x << std::endl;
// //     }

// //     return 0;
// // }
