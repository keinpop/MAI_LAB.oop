#include "./header/square.h"
#include "./header/triangle.h"
#include "./header/octagon.h"
#include "./header/arrayFig.h"

int main()
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    
    Square sq(test1);

    std::vector<Coord> test2;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test2.push_back(t1);
    test2.push_back(t2);
    test2.push_back(t3);

    Triangle tr(test2);

    std::vector<Coord> test3;
    Coord oc1 = {4, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {0, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {4, 1};
    test3.push_back(oc1);
    test3.push_back(oc2);
    test3.push_back(oc3);
    test3.push_back(oc4);
    test3.push_back(oc5);
    test3.push_back(oc6);
    test3.push_back(oc7);
    test3.push_back(oc8);

    Octagon oc(test3);

    ArrayFig a;
    a.pushBack(&sq);
    a.pushBack(&tr);
    a.pushBack(&oc);

    std::cout << a << std::endl;
    a.printAreas();
    a.printGeomCenters();
    std::cout << "Sum of all area in array = " << (double)a << std::endl;
    
    return 0;
}