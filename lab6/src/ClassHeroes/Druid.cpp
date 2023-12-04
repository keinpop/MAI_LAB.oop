#include "../../header/ClassHeroes/Druid.h"

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

int Druid::accept(Visitor & visitor)
{
    return visitor.visit(*this);
}