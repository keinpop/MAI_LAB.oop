#include "../../header/ClassHeroes/Squirrel.h"

bool SquirrelVisitor::visit(const std::shared_ptr<Squirrel>& attacker) const {
    return false;
}

bool SquirrelVisitor::visit(const std::shared_ptr<Druid>& attacker) const {
    return false;
}

bool SquirrelVisitor::visit(const std::shared_ptr<Werewolf>& attacker) const {
    return false;
}

Squirrel::Squirrel(std::string hName, short int x, short int y) : Heroes(SQUIRREL, hName, x, y, RANGE_ATTACK_SQ, RANGE_MOVE_SQ) {}

Squirrel::Squirrel(std::istream & is) : Heroes(SQUIRREL, is)
{
    _rangeAttack = RANGE_ATTACK_SQ;
    _rangeMove = RANGE_MOVE_SQ;
}

void Squirrel::print()
{
    std::cout << *this;
}

void Squirrel::save(std::ostream & os)
{
    os << SQUIRREL << std::endl;
    Heroes::save(os);
}

std::ostream & operator<<(std::ostream & os, Squirrel & sq)
{
    os << "Squirrel: " << *static_cast<Heroes*> (&sq) << std::endl;
    return os;
}

int Squirrel::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker)
{
    std::shared_ptr<const Heroes> npc_const_ptr = shared_from_this();
    std::shared_ptr<Heroes> npc_ptr = std::const_pointer_cast<Heroes>(npc_const_ptr);
    std::shared_ptr<Squirrel> defender = std::dynamic_pointer_cast<Squirrel>(npc_ptr);
    
    bool result = attacker_visitor->visit(defender);
    
    if (result) {
        int pointAttacker = throwTheDice();
        int pointDefender = throwTheDice();
        if (pointAttacker <= pointDefender) {
            result = false;
        }
    } 
    attacker->fightNotify(defender, result);

    return result;
}