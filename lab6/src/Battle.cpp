#include "../header/Battle.h"

set_t battle(const set_t & array)
{
    set_t killBar;

    for (const auto & attacker : array) {
        for (const auto & defender : array) {
            if ((attacker != defender) && (attacker->isClose(defender))) {
                HeroesPair fighters;
                FightVisitor vis;
                fighters.first = attacker;
                fighters.second = defender;

                int res = fighters.accept(vis);
                
                if (res == 1) {
                    killBar.insert(defender);
                }
            }
        }
    }

    return killBar;
}

std::ostream & operator<<(std::ostream & os, const set_t & array)
{
    for (auto & n : array) {
        n->print();
    }

    return os;
}

void save(const set_t & array, const std::string & filename)
{
    std::ofstream fs(filename);

    fs << array.size() << std::endl;

    for (auto & n : array) {
        n->save(fs);
    }

    fs.flush();
    fs.close();
}

set_t load(const std::string & filename)
{
    set_t res;
    std::ifstream is(filename);
    Factory fac;

    if (is.good() && is.is_open()) {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i) {
            res.insert(fac.createHero(is));
        }

        is.close();
    } else {
        throw std::invalid_argument("Error! load : file is not correctly");
    }

    return res;
}