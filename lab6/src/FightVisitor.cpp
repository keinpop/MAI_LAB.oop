#include "../header/FightVisitor.h"

int FightVisitor::visit(Squirrel & sq)
{
    return 3;
}

int FightVisitor::visit(Werewolf & wf)
{
    return 2;
}

int FightVisitor::visit(Druid & dr)
{
    return 1;
}

int FightVisitor::visit(HeroesPair & hp)
{
    FightVisitor tmp;

    int result = hp.first->accept(tmp);
    result -= hp.second->accept(tmp);

    if (result == 1 || result == 2) {
        hp.first->fightNotify(hp.second, true);
        return true;
    } else {
        hp.first->fightNotify(hp.second, false);
        return false;   
    }
}