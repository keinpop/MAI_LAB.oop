#include <iostream>

#include "./header/seven.h"

int main()
{
    // Seven s1(5, '0');
    // Seven s2(5, '0');

    // try
    // {
    //     std::cin >> s1;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // try
    // {
    //     std::cin >> s2;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // Seven s3 = s1 + s2;
    // Seven s4 = s3 - s2;
    
    // std::cout << s3 << std::endl;
    // std::cout << s4 << std::endl;
    
    // Seven s5 = s2;
    // if (s4 < s3)
    //     std::cout << std::boolalpha << true << std::endl;
    // else std::cout << false << std::endl;

    // if (s5 == s2) 
    //     std::cout << true << std::endl;
    // else std::cout << false << std::endl;

    // Seven s6 = s3;
    // s1 += s2;

    // if (s6 == s1) 
    //     std::cout << true << std::endl;
    // else std::cout << false << std::boolalpha << std:: endl;

    Seven s1 {'1', '2', '3'};
    Seven s2 {'2', '3', '5'};
    Seven s3 {'3', '6', '1'};
    Seven s4(3, '0');
    s4 = s1 + s2;

    std::cout << s3 << ' ' << s4 << std::endl;
    

    return 0;
}