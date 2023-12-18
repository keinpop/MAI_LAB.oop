#include "../header/FightManager.h"

FightManager & FightManager::get()
{
    static FightManager inst;
    
    return inst;
}

void FightManager::addEvent(FightEvent && event)
{
    std::lock_guard<std::shared_mutex> lock(_mtx);
    _events.push(event);
}

std::unordered_map<HeroesClass, std::shared_ptr<Visitor>> visitors = {
    {DRUID, std::make_shared<SquirrelVisitor>()},
    {SQUIRREL, std::make_shared<DruidVisitor>()},
    {WEREWOLF, std::make_shared<WerewolfVisitor>()}
};

void FightManager::operator()()
{
    while(true) {
        if (_timer == MAX_TIME) {
            return;
        }
        std::optional<FightEvent> event;
        {
            std::lock_guard<std::shared_mutex> lock(_mtx);
            if (!_events.empty()) {
                event = _events.back();
                _events.pop();
            }
        }
        
        if (event) {
            if (event->attacker->isAlive()) {
                if (event->defender->isAlive()) {
                    if (event->defender->accept(visitors[event->attacker->getType()], event->attacker)) {
                        event->defender->mustDie();
                    }
                }
            }
        }
        
    }
}