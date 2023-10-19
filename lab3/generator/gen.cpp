#include <iostream>
#include <cmath>

typedef struct _coordinates {
    double x;
    double y;
} Coord;

void generateCoordSquare(Coord basicPoint, double lengthSide, double angle) {
    angle = angle * M_PI / 180.0;

    Coord vertices[4];

    if ((int)angle % 45 == 0) {
        for (int i = 0; i < 4; ++i) {
            double x = round(basicPoint.x + lengthSide * std::cos(angle));
            double y = round(basicPoint.y + lengthSide * std::sin(angle));
            vertices[i] = {x, y};
            angle += M_PI / 2.0;
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            double x = basicPoint.x + lengthSide * std::cos(angle);
            double y = basicPoint.y + lengthSide * std::sin(angle);
            vertices[i] = {x, y};
            angle += M_PI / 2.0;
        }
    }

    

    for (int i = 0; i < 4; ++i) {
        std::cout << "Vertex " << i + 1 << ": (" << vertices[i].x << ", " << vertices[i].y << ")" << std::endl;
    }
}

void generateCoordTriangle(Coord basicPoint, double lengthSide, double angle) {
    angle = angle * M_PI / 180.0;

    Coord vertices[3];

    if ((int)angle % 30 == 0) {
        for (int i = 0; i < 3; ++i) {
            double x = round(basicPoint.x + lengthSide * std::cos(angle));
            double y = round(basicPoint.y + lengthSide * std::sin(angle));
            vertices[i] = {x, y};
            angle += (2.0 * M_PI / 3.0); 
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            double x = basicPoint.x + lengthSide * std::cos(angle);
            double y = basicPoint.y + lengthSide * std::sin(angle);
            vertices[i] = {x, y};
            angle += (2.0 * M_PI / 3.0);
        }
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << "Coord " << i + 1 << ": {" << vertices[i].x << ", " << vertices[i].y << "}" << std::endl;
    }
}

void generateCoordOctagon(Coord basicPoint, double lengthSide, double angle) {
    angle = angle * M_PI / 180.0;

    Coord vertices[8];

    if (int(angle) % (int)22.5 == 0) {
        for (int i = 0; i < 8; ++i) {
            double x = round(basicPoint.x + lengthSide * std::cos(angle));
            double y = round(basicPoint.y + lengthSide * std::sin(angle));
            vertices[i] = {x, y};
            angle += (M_PI / 4.0);
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            double x = basicPoint.x + lengthSide * std::cos(angle);
            double y = basicPoint.y + lengthSide * std::sin(angle);
            vertices[i] = {x, y};
            angle += (M_PI / 4.0);
        }
    }

    for (int i = 0; i < 8; ++i) {
        std::cout << "Coord " << i + 1 << ": {" << vertices[i].x << ", " << vertices[i].y << "}" << std::endl;
    }
}

int main() {
    Coord basicPoint = {1.0, 1.0};
    double lengthSide = 1.0; 
    double angle = 22.5; 

    generateCoordOctagon(basicPoint, lengthSide, angle);

    return 0;
}
