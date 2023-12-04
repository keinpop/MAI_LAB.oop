#pragma once

#include "../Heroes.h"

class Werewolf : public Heroes {
public:
    Werewolf(std::string hName, short int x, short int y);
    Werewolf(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Werewolf & wf);
    virtual int accept(Visitor & visitor) override;
};
