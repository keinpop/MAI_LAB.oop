#pragma once

#include "../Heroes.h"

struct SquirrelVisitor : public Visitor 
{
    bool visit(const std::shared_ptr<Werewolf>&) const override;
    bool visit(const std::shared_ptr<Druid>&) const override;
    bool visit(const std::shared_ptr<Squirrel>&) const override;
};  

class Squirrel final : public Heroes {
public:
    Squirrel(std::string hName, short int x, short int y);
    Squirrel(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Squirrel & sq);
    virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker) override;
};