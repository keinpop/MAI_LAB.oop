#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <cmath>
#include <memory>
#include <set>
#include <vector>
#include <mutex>

#include "./ClassHeroes/ClassAndNameHeroes.h"

class Heroes;
class HeroesPair;
class Squirrel;
class Werewolf;
class Druid;
using set_t = std::set<std::shared_ptr<Heroes>>;

class IFightObserver 
{
public:
    virtual void onFight(
        const std::shared_ptr<Heroes> attacker, 
        const std::shared_ptr<Heroes> defender, bool win
    ) = 0;
};

struct Visitor 
{
    virtual bool visit(const std::shared_ptr<Squirrel>&) const = 0;
    virtual bool visit(const std::shared_ptr<Druid>&) const = 0;
    virtual bool visit(const std::shared_ptr<Werewolf>&) const = 0;
};

class Heroes : public std::enable_shared_from_this<Heroes>
{
public:
    Heroes() = default;
    Heroes(HeroesClass hClass, std::string hName, int x, int y, int rA, int rM);
    Heroes(HeroesClass hClass, std::istream & is);

    virtual ~Heroes() = default;

    std::string getName() const;
    HeroesClass & getType();
    int getRangeMove() const;
    std::pair<int, int> position();

    void subscribe(std::shared_ptr<IFightObserver> obs);
    void fightNotify(const std::shared_ptr<Heroes> defender, bool win);
    virtual bool isClose(const std::shared_ptr<Heroes> & other);
    
    virtual void print() = 0;
    virtual void save(std::ostream & os);
    friend std::ostream & operator<<(std::ostream & os, Heroes & heroes);

    virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker) = 0;

    void move(int shiftX, int shiftY, int maxX, int maxY);

    bool isAlive();
    void mustDie();

private:
    std::mutex mtx;

protected:
    int _x {0};
    int _y {0};

    int _rangeAttack{0};
    int _rangeMove{0};

    bool _alive{true};
    HeroesClass _type;
    std::string _name;
    std::vector<std::shared_ptr<IFightObserver>> _obs;
};