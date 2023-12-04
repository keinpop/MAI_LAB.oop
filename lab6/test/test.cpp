#include <gtest/gtest.h>

#include "../header/Battle.h"

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
    try{
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

TEST(test_04, CloseTest)
{

    Squirrel a(getRandNameSq(), 1, 1);

    std::shared_ptr<Heroes> f = std::shared_ptr<Heroes>(new Squirrel(getRandNameSq(), 99, 0));
    
    ASSERT_TRUE(a.isClose(f));
}

TEST(test_05, VisitTest)
{

    Squirrel sq(getRandNameSq(), 1, 100);
    Druid dr(getRandNameDr(), 100, 1);
    FightVisitor t;

    ASSERT_TRUE(3 == t.visit(sq));
    ASSERT_TRUE(3 == sq.accept(t));
    ASSERT_TRUE(1 == t.visit(dr));
    ASSERT_TRUE(1 == dr.accept(t));
}

TEST(test_06, NoDeathFighterTest)
{

    set_t array;

    Factory factor;

    array.insert(factor.createHero(SQUIRREL, 0, 0));
    array.insert(factor.createHero(WEREWOLF, 100, 100));
    array.insert(factor.createHero(DRUID, 200, 200));

    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_07, DeathFighterTest)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(SQUIRREL, 0, 0));
    array.insert(factor.createHero(WEREWOLF, 0, 100));
    array.insert(factor.createHero(DRUID, 1, 99));

    set_t dead = battle(array);

    bool result = (dead.size() == 2);

    EXPECT_TRUE(result);
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

TEST(test_11, SquirrelWithWerewolfFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(SQUIRREL, 10, 10));
    array.insert(factor.createHero(WEREWOLF, 0, 0));
    array.insert(factor.createHero(WEREWOLF, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 2);

    EXPECT_TRUE(result);
}

TEST(test_12, SquirrelWithDruidFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(SQUIRREL, 10, 10));
    array.insert(factor.createHero(DRUID, 0, 0));
    array.insert(factor.createHero(DRUID, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 2);

    EXPECT_TRUE(result);
}

TEST(test_13, WerewolfWithSquirrelFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(WEREWOLF, 10, 10));
    array.insert(factor.createHero(SQUIRREL, 0, 0));
    array.insert(factor.createHero(SQUIRREL, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 1);

    EXPECT_TRUE(result);
}

TEST(test_14, SquirrelWithDruidFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(WEREWOLF, 10, 10));
    array.insert(factor.createHero(DRUID, 0, 0));
    array.insert(factor.createHero(DRUID, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 2);

    EXPECT_TRUE(result);
}

TEST(test_15, DruidWithSquirrelFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(DRUID, 10, 10));
    array.insert(factor.createHero(SQUIRREL, 0, 0));
    array.insert(factor.createHero(SQUIRREL, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 1);

    EXPECT_TRUE(result);
}

TEST(test_16, DruidWithWerewolfFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(DRUID, 10, 10));
    array.insert(factor.createHero(WEREWOLF, 0, 0));
    array.insert(factor.createHero(WEREWOLF, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 1);

    EXPECT_TRUE(result);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}