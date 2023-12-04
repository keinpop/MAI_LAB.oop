#include "../../header/ClassHeroes/Squirrel.h"

Squirrel::Squirrel(std::string hName, short int x, short int y) : Heroes(SQUIRREL, hName, x, y) {}

Squirrel::Squirrel(std::istream & is) : Heroes(SQUIRREL, is) {}

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

int Squirrel::accept(Visitor & visitor)
{
    return visitor.visit(*this);
}