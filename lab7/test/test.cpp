#include <gtest/gtest.h>

#include "../header/FightManager.h"

std::unordered_map<HeroesClass, std::shared_ptr<Visitor>> v = {
    {DRUID, std::make_shared<SquirrelVisitor>()},
    {SQUIRREL, std::make_shared<DruidVisitor>()},
    {WEREWOLF, std::make_shared<WerewolfVisitor>()}
};

TEST(test_00, FabricTest)
{
    set_t arr;
    Factory fact;

    arr.insert(fact.createHero(SQUIRREL, 1, 2));
    arr.insert(fact.createHero(WEREWOLF, 3, 4));
    arr.insert(fact.createHero(DRUID, 5, 6));

    bool res = (arr.size() == 3);

    EXPECT_TRUE(res);
}

TEST(test_01, SquirrelConstructorTest)
{
    bool test = true;
    try {
        Squirrel(getRandNameSq(), 17, 17);
    } catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}

TEST(test_02, WerewolfConstructorTest)
{

    bool test = true;
    try{
        Werewolf(getRandNameWf(), 17, 17);
    } catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}

TEST(test_03, DruidConstructorTest)
{

    bool test = true;
    try{
        Druid(getRandNameDr(), 17, 17);
    } catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}

TEST(test_04, CloseTestSquirrel)
{

    Squirrel a(getRandNameSq(), 1, 1);

    std::shared_ptr<Heroes> f = std::shared_ptr<Heroes>(new Druid(getRandNameSq(), 5, 0));
    
    ASSERT_TRUE(a.isClose(f));
}

TEST(test_05, CloseTestWerewolf)
{

    Werewolf a(getRandNameWf(), 1, 1);

    std::shared_ptr<Heroes> f = std::shared_ptr<Heroes>(new Druid(getRandNameSq(), 5, 0));
    
    ASSERT_TRUE(a.isClose(f));
}

TEST(test_06, CloseTestDruid)
{

    Druid a(getRandNameDr(), 1, 1);

    std::shared_ptr<Heroes> f = std::shared_ptr<Heroes>(new Druid(getRandNameSq(), 9, 0));
    
    ASSERT_TRUE(a.isClose(f));
}

TEST(test_07, CloseTestFalse)
{

    Squirrel a(getRandNameSq(), 1, 1);

    std::shared_ptr<Heroes> f = std::shared_ptr<Heroes>(new Druid(getRandNameSq(), 7, 0));
    
    ASSERT_FALSE(a.isClose(f));
}

TEST(test_08, SquirrelFightTest)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(SQUIRREL, 0, 0));
    array.insert(factor.createHero(SQUIRREL, 0, 1));
    array.insert(factor.createHero(SQUIRREL, 0, 2));
    
    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_09, WerewolfFightTest)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(WEREWOLF, 0, 0));
    array.insert(factor.createHero(WEREWOLF, 0, 1));
    array.insert(factor.createHero(WEREWOLF, 0, 2));
    
    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_10, DruidFightTest)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(DRUID, 0, 0));
    array.insert(factor.createHero(DRUID, 0, 1));
    array.insert(factor.createHero(DRUID, 0, 2));
    
    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_11, SquirrelWithWerewolfAndDruidFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(SQUIRREL, 10, 10));
    array.insert(factor.createHero(WEREWOLF, 11, 11));
    array.insert(factor.createHero(DRUID, 11, 12));

    bool win = false;
    int countD = 0;
    while (!win) {
        if (countD == 2) {
            win = true;
        }
        for (std::shared_ptr<Heroes> npc : array) {
            for (std::shared_ptr<Heroes> other : array) {
                if (other != npc) {
                    if (npc->isAlive()) {
                        if(other->isAlive()) {
                            if (npc->isClose(other)) {
                                if (other->accept(v[npc->getType()], npc)) {
                                    other->mustDie();
                                    ++countD;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ASSERT_TRUE(win);
}

TEST(test_12, WerewolfWithDruidFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(WEREWOLF, 10, 10));
    array.insert(factor.createHero(DRUID, 11, 11));
    array.insert(factor.createHero(DRUID, 11, 12));

    bool win = false;
    int countD = 0;
    while (!win) {
        if (countD == 2) {
            win = true;
        }
        for (std::shared_ptr<Heroes> npc : array) {
            for (std::shared_ptr<Heroes> other : array) {
                if (other != npc) {
                    if (npc->isAlive()) {
                        if(other->isAlive()) {
                            if (npc->isClose(other)) {
                                if (other->accept(v[npc->getType()], npc)) {
                                    other->mustDie();
                                    ++countD;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ASSERT_TRUE(win);
}

TEST(test_13, UltimateFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(SQUIRREL, 10, 10));
    array.insert(factor.createHero(DRUID, 11, 11));
    array.insert(factor.createHero(WEREWOLF, 11, 12));
    array.insert(factor.createHero(DRUID, 11, 13));
    array.insert(factor.createHero(DRUID, 11, 14));
    array.insert(factor.createHero(WEREWOLF, 11, 15));
    array.insert(factor.createHero(DRUID, 11, 100));

    bool win = false;
    int countD = 0;
    while (!win) {
        if (countD == 4) {
            win = true;
        }
        for (std::shared_ptr<Heroes> npc : array) {
            for (std::shared_ptr<Heroes> other : array) {
                if (other != npc) {
                    if (npc->isAlive()) {
                        if(other->isAlive()) {
                            if (npc->isClose(other)) {
                                if (other->accept(v[npc->getType()], npc)) {
                                    other->mustDie();
                                    ++countD;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ASSERT_TRUE(win);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}