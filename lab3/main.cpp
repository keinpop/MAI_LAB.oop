#include "./header/square.h"

int main()
{
    Square c;

    std::cin >> c;
    std::cout << c;

    Square d = c;


    std::cout << (d == c) << std::endl;;

    return 0;
}