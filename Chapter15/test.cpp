#include <iostream>
#include <typeinfo>

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
};

// int main()
// {
//     // Base* basePtr = new Derived;

//     // const std::type_info& typeInfo = typeid(*basePtr);

//     // std::cout << "Type information: " << typeInfo.name() << std::endl;

//     // delete basePtr;

//     try
//     {
//         // some code that may throw an exception
//         throw std::runtime_error("Something went wrong");
//     }
//     catch (const std::exception &e)
//     {
//         // handle the exception
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }