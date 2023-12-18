#pragma once

#include <iostream>
#include <ctime>

enum HeroesClass{
    SQUIRREL = 0,
    WEREWOLF,
    DRUID
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

int throwTheDice();