#include <raylib.h>

typedef struct Wall {
    Rectangle rect;
    struct Wall *suiv;
}Wall;

Wall *wallCreation(float width, float height, float x, float y);
void addLastWall(Wall *wall, float width, float height, float x, float y);
void destroyLastWall(Wall *wall);
void showWalls(Wall *walls);