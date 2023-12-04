#pragma once

#include <iostream>
#include <ctime>

#define DISTANCE_FIGHT 100

enum HeroesClass{
    UNDEFIEND = 0,
    SQUIRREL = 3,
    WEREWOLF = 2,
    DRUID = 1
};

const std::string SquirrelName[10] = {
    "Scrat", "Hoodwink", "Arriel", 
    "Mortra", "Jarry", "Shtorm",
    "Arsi", "Mexa", "Arta", "Shi"
};

const std::string WerewolfName[10] = {
    "Lycan", "Shay", "Oskar",
    "Lovel", "Arald", "Beorn",
    "Victor", "Mara", "Greg", "Amon"
};

const std::string DruidName[10] = {
    "Phurion", "Trent", "Malith",
    "Tris", "Valrai", "Barlius",
    "Daspira", "Dayis", "Savari", "Naphi"
};

std::string getRandNameSq();
std::string getRandNameWf();
std::string getRandNameDr();