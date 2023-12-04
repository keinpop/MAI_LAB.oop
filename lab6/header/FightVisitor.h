#pragma once

#include "./FactoryHeroes.h"
#include "./HeroesPair.h"

class FightVisitor final : public Visitor
{
public:
    virtual int visit(Squirrel & sq);
    virtual int visit(Werewolf & wf);
    virtual int visit(Druid & dr);
    virtual int visit(HeroesPair & hp);
};