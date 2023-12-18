#include "../header/FactoryHeroes.h"

std::shared_ptr<Heroes> Factory::createHero(HeroesClass hClass, short int x, short int y) {
    std::string hName;
    std::shared_ptr<Heroes> res;
    switch (hClass) {
        case HeroesClass::SQUIRREL:
            hName = getRandNameSq();
            res = std::make_shared<Squirrel>(hName, x, y);
            break;
        case HeroesClass::WEREWOLF:
            hName = getRandNameWf();
            res = std::make_shared<Werewolf>(hName, x, y);
            break;
        case HeroesClass::DRUID:
            hName = getRandNameDr();
            res = std::make_shared<Druid>(hName, x, y);
            break;
        default:
            throw std::invalid_argument("Error! createHero to param : invalid HeroesClass");
            break;
    }

    if (res) {
        res->subscribe(TextObserver::get());
        res->subscribe(FileObserver::get());
    }

    return res;
}

std::shared_ptr<Heroes> Factory::createHero(std::istream & is) {
    int hClass{0};
    std::shared_ptr<Heroes> res;
    if (is >> hClass) {
        switch (hClass) {
            case SQUIRREL:
                res = std::make_shared<Squirrel>(is);
                break;
            case WEREWOLF:
                res = std::make_shared<Werewolf>(is);
                break;
            case DRUID:
                res = std::make_shared<Druid>(is);
                break;
            default:
                throw std::invalid_argument("Error! createHero to file : invalid HeroesClass");
                break;
        }
    } else {
        std::cout <<"Huy\n";
        throw std::invalid_argument("Error! createHero to file : invalid enter into file");
    }

    if (res) {
        res->subscribe(TextObserver::get());
        res->subscribe(FileObserver::get());
    }

    return res;
}