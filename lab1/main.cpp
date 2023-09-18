//var 8
#include "eub.h"

int main()
{
    std::string str = "";

    std::cout << "Please enter a binary number to be converted by the task: ";
    std::cin >> str;
    std::cout << eliminateUnsetBits(str) << std::endl;

    return 0;
}