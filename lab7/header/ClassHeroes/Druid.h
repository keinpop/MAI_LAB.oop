#pragma once

#include "../Heroes.h"

#define RANGE_ATTACK_DR 10
#define RANGE_MOVE_DR 10

struct DruidVisitor : public Visitor
{
    bool visit(const std::shared_ptr<Werewolf>&) const override;
    bool visit(const std::shared_ptr<Druid>&) const override;
    bool visit(const std::shared_ptr<Squirrel>&) const override;
};


class Druid final : public Heroes {
public:
    Druid(std::string hName, short int x, short int y);
    Druid(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Druid & dr);
    virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker) override;
};  
