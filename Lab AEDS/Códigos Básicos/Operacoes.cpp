#include <iostream>
int main()
{
    // Declare three Boolean variables
    int a = 3, b = 2;
    int c = a&b;
    int d = a|b;
    int e =  (a||b);
    int f = !(a||b);
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";
    std::cout << e << "\n";
    std::cout << f << "\n";
}