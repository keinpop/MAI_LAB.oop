#pragma once

#include "./Heroes.h"

class HeroesPair
{
public:
    virtual int accept(Visitor & visitor) 
    {
        return visitor.visit(*this);
    }

    std::shared_ptr<Heroes> first;
    std::shared_ptr<Heroes> second;
};