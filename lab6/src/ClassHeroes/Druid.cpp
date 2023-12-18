#include "../../header/ClassHeroes/Druid.h"

bool DruidVisitor::visit(const std::shared_ptr<Squirrel>& attacker) const {
    return false;
}

bool DruidVisitor::visit(const std::shared_ptr<Druid>& attacker) const {
    return true;
}

bool DruidVisitor::visit(const std::shared_ptr<Werewolf>& attacker) const {
    return true;
}

Druid::Druid(std::string hName, short int x, short int y) : Heroes(DRUID, hName, x, y) {}

Druid::Druid(std::istream & is) : Heroes(DRUID, is) {}

void Druid::print()
{
    std::cout << *this;
}

void Druid::save(std::ostream & os)
{
    os << DRUID << std::endl;
    Heroes::save(os);
}

std::ostream & operator<<(std::ostream & os, Druid & dr)
{
    os << "Druid: " << *static_cast<Heroes*> (&dr) << std::endl;
    return os;
}

int Druid::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker)
{
    std::shared_ptr<const Heroes> npc_const_ptr = shared_from_this();
    std::shared_ptr<Heroes> npc_ptr = std::const_pointer_cast<Heroes>(npc_const_ptr);
    std::shared_ptr<Druid> defender = std::dynamic_pointer_cast<Druid>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fightNotify(defender, result);

    return result;
}