#pragma once

#include "../Heroes.h"

class Squirrel final : public Heroes {
public:
    Squirrel(std::string hName, short int x, short int y);
    Squirrel(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Squirrel & sq);
    virtual int accept(Visitor & visitor) override;
};