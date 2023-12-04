#include "../../header/ClassHeroes/Werewolf.h"

Werewolf::Werewolf(std::string hName, short int x, short int y) : Heroes(WEREWOLF, hName, x, y) {}

Werewolf::Werewolf(std::istream & is) : Heroes(WEREWOLF ,is) {}

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

int Werewolf::accept(Visitor & visitor)
{
    return visitor.visit(*this);
}