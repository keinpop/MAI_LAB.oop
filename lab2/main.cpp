#include <iostream>

#include "./header/seven.h"

int main()
{
    Seven a = Seven();
    size_t n;
    std::cout << "Enter number of arr: ";
    std::cin >> n;

    unsigned char* arr = new unsigned char(n);
    
    std::cout << "Enter element of arr: ";

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
    }

    std::cout << std::endl;

    return 0;
}