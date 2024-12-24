#ifndef WALLS_H
#define WALLS_H

#include <raylib.h>

typedef struct Wall {
    Rectangle rect;
    int rank;
    struct Wall *suiv;
}Wall;

Wall *wallCreation(float width, float height, float x, float y);
void addLastWall(Wall *wall, float width, float height, float x, float y);
void destroyRankWall(Wall *walls, int rank);
void showWalls(Wall *walls);
void freeWalls(Wall *walls);

#endif