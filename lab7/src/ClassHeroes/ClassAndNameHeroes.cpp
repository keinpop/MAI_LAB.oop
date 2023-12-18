#include "../../header/ClassHeroes/ClassAndNameHeroes.h"

std::string getRandNameSq()
{
    std::string hName = SquirrelName[(std::rand()) % 10];
    
    return hName;
}

std::string getRandNameWf()
{
    std::string hName = WerewolfName[(std::rand()) % 10];
    
    return hName;
}

std::string getRandNameDr()
{
    std::string hName = DruidName[(std::rand()) % 10];
    
    return hName;
}

int throwTheDice()
{   
    return (rand() % 6) + 1;
}