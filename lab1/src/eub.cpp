#include "../header/eub.h"

unsigned long eliminateUnsetBits(const std::string & number)
{
    if (number.size() == 0 || number[0] == ' ') { // checking to valid enter 
        std::cout << "\tInvalid enter (empty row)\n";
        return -1;
    }

    size_t strLength = number.size();

    int countOfPow = 0;
    for (int i = 0; i < strLength; i++) {
        if (number[i] != '0') {
            countOfPow++;
        }
    }

    if (countOfPow > 32) {
        std::cout << "Invalid enter (Invalid size number)" << std::endl;
        return -1;
    }

    return (pow(BINARY_NUM, countOfPow) - 1) ;
}