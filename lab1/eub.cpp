#include "eub.h"

long binaryToDecimal(long binNum) 
{
    unsigned int countDigit = 0;
    int lastDigit = binNum;
    long result = 0;

    while (binNum != 0) {
        lastDigit %= 10;
        binNum /= 10;
        result += lastDigit * pow(BINARY_NUM, countDigit);
        countDigit++;
    }
    
    return result;
}

long eliminateUnsetBits(std::string number)  
{
    long result;
    if (number.length() == 0 || number[0] == ' ') { // checking to valid enter 
        std::cout << "\tInvalid enter (empty row)\n";
        return -1;
    }

    std::string strNum = "";
    size_t strLength = number.size();
    int countLengthRes = 0;
    int counterValidNumb = 0;

    for (int i = 0; i < strLength; i++) {
        if (number[i] != '0') {
            strNum[countLengthRes] = number[i];
            countLengthRes++;
            counterValidNumb++;
        }
    }

    if (counterValidNumb == 0) {
        return 0;
    }

    long strToNum = stoul(strNum); // stoul == String To Unsigned Long;
    result = binaryToDecimal(strToNum);

    if (counterValidNumb > 10) { // out of bounds long value
        std::cout << "\tInvalid enter (overflow enter)\n";
        return -1;
    }

    return result;
}