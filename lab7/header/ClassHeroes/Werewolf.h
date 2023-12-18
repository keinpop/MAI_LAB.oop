#pragma once

#include "../Heroes.h"

#define RANGE_ATTACK_WF 5
#define RANGE_MOVE_WF 40

struct WerewolfVisitor : public Visitor 
{
    bool visit(const std::shared_ptr<Werewolf>&) const override;
    bool visit(const std::shared_ptr<Druid>&) const override;
    bool visit(const std::shared_ptr<Squirrel>&) const override;
};  

class Werewolf : public Heroes {
public:
    Werewolf(std::string hName, short int x, short int y);
    Werewolf(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Werewolf & wf);
    virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker) override;
};
