#pragma once

#include "../Heroes.h"

class Druid final : public Heroes {
public:
    Druid(std::string hName, short int x, short int y);
    Druid(std::istream & is);

    void print() override;
    void save(std::ostream & os) override;
    friend std::ostream & operator<<(std::ostream & os, Druid & dr);
    virtual int accept(Visitor & visitor) override;
};  
