#include "./header/Battle.h"
#include <random>
#include <chrono>
#include <thread>

int main()
{
    srand(time(nullptr));
    std::cout << "Generating ..." << std::endl;

    set_t arr;
    Factory fact;

    for (size_t i = 0; i < 50; ++i) {
        HeroesClass r = static_cast<HeroesClass>((std::rand() % 3) + 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        arr.insert(fact.createHero(r, std::rand() % 500, std::rand() % 500));
    }

    std::cout << "Saving ..." << std::endl;
    save(arr, "./npc.txt");

    std::cout << "Loading ..." << std::endl;
    arr = load("./npc.txt");
    for (size_t dist = DISTANCE_FIGHT; (dist <= 500) && !(arr.empty()); dist += 10) {
        auto kb = battle(arr);

        for (auto & d : kb) {
            arr.erase(d);
        }

        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << DISTANCE_FIGHT << std::endl
                  << "killed: " << kb.size() << "\n\n\n";
    }

    std::cout << "Survivors: " << arr;

    return 0;
}