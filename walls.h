#ifndef WALLS_H
#define WALLS_H

#include <raylib.h>

typedef struct Wall {
    Rectangle rect;
    char *type;
    struct Wall *suiv;
}Wall;


Wall *wallCreation(float width, float height, float x, float y, char *type);
void addLastWall(Wall *wall, float width, float height, float x, float y, char *type);
void showWalls(Wall *walls);
void freeWalls(Wall *walls);

#endif