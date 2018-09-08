#include <iostream>
int main(int argc, char *argv[])
{
    unsigned int a = 0x100;
    unsigned int b = 0x010;
    unsigned int c  = a|b;

    std::cout << a  << "\n";
    std::cout << b  << "\n";
    std::cout << c  << "\n";


    return 0;
}
