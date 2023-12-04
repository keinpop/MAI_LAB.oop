#include "../../header/ClassHeroes/ClassAndNameHeroes.h"

std::string getRandNameSq()
{
    std::srand(std::time(nullptr));
    std::string hName = SquirrelName[(std::rand()) % 10];
    
    return hName;
}

std::string getRandNameWf()
{
    std::srand(std::time(nullptr));
    std::string hName = WerewolfName[(std::rand()) % 10];
    
    return hName;
}

std::string getRandNameDr()
{
    std::srand(std::time(nullptr));
    std::string hName = DruidName[(std::rand()) % 10];
    
    return hName;
}