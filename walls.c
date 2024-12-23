#include <raylib.h>
#include <stdlib.h>

#include "player.h"
#include "walls.h"


Wall *wallCreation(float width, float height, float x, float y) {
    srand(time(NULL));
    Wall *wall = (Wall *) malloc(sizeof(Wall));
    wall->rect.height = height;
    wall->rect.width = width;
    wall->rect.x = x;
    wall->rect.y = y;
    wall->suiv = NULL;
    return wall;
}

void addLastWall(Wall *wall, float width, float height, float x, float y){
    Wall *w = wallCreation(width, height, x, y);
    while(wall->suiv != NULL) {
        wall = wall->suiv;
    }
    wall->suiv = w;
}

void destroyLastWall(Wall *wall) {
    if (wall == NULL) { 
        return;
    }
    if (wall->suiv == NULL) { 
        free(wall);
        wall = NULL;
        return;
    }
    Wall *tmp = wall;
    while (tmp->suiv->suiv != NULL) {
        tmp = tmp->suiv;
    }
    free(tmp->suiv);
    tmp->suiv = NULL;
}

void showWalls(Wall *walls) {
    Wall *tmp = walls;
    while(tmp != NULL) {
        DrawRectangleRec(tmp->rect, RAYWHITE);
        tmp = tmp->suiv;
    }
}

void freeWalls(Wall *walls) {
    Wall *tmp;
    while (walls) {
        tmp = walls->suiv;
        free(walls);
        walls = tmp;
    }
}