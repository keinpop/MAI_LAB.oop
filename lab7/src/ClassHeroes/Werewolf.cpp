#include "../../header/ClassHeroes/Werewolf.h"

bool WerewolfVisitor::visit(const std::shared_ptr<Squirrel>& attacker) const {
    return false;
}

bool WerewolfVisitor::visit(const std::shared_ptr<Druid>& attacker) const {
    return true;
}

bool WerewolfVisitor::visit(const std::shared_ptr<Werewolf>& attacker) const {
    return false;
}


Werewolf::Werewolf(std::string hName, short int x, short int y) : Heroes(WEREWOLF, hName, x, y, RANGE_ATTACK_WF, RANGE_MOVE_WF) {}

Werewolf::Werewolf(std::istream & is) : Heroes(WEREWOLF ,is) 
{
    _rangeAttack = RANGE_ATTACK_WF;
    _rangeMove = RANGE_MOVE_WF;
}

void Werewolf::print()
{
    std::cout << *this;
}

void Werewolf::save(std::ostream & os)
{
    os << WEREWOLF << std::endl;
    Heroes::save(os);
}

std::ostream & operator<<(std::ostream & os, Werewolf & wf)
{
    os << "Werewolf: " << *static_cast<Heroes*> (&wf) << std::endl;
    return os;
}

int Werewolf::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker)
{
    std::shared_ptr<const Heroes> npc_const_ptr = shared_from_this();
    std::shared_ptr<Heroes> npc_ptr = std::const_pointer_cast<Heroes>(npc_const_ptr);
    std::shared_ptr<Werewolf> defender = std::dynamic_pointer_cast<Werewolf>(npc_ptr);

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