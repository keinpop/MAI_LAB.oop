#pragma once

#include "./ClassHeroes/Squirrel.h"
#include "./ClassHeroes/Werewolf.h"
#include "./ClassHeroes/Druid.h"
#include "./Observer.h"
 
#include <cstdlib>

class Factory
{
public:
    std::shared_ptr<Heroes> createHero(HeroesClass hClass, short int x, short int y);
    std::shared_ptr<Heroes> createHero(std::istream & is);
};