#include <raylib.h>
#include <stdlib.h>

#include "player.h"
#include "walls.h"


Wall *wallCreation(float width, float height, float x, float y) {
    Wall *wall = (Wall *) malloc(sizeof(Wall));
    wall->rank = 1;
    wall->rect.height = height;
    wall->rect.width = width;
    wall->rect.x = x;
    wall->rect.y = y;
    wall->suiv = NULL;
    return wall;
}

void addLastWall(Wall *walls, float width, float height, float x, float y){
    Wall *w = wallCreation(width, height, x, y);
    int i = 1;
    while(walls->suiv != NULL) {
        walls = walls->suiv;
        i++;
    }
    i++;
    walls->suiv = w;
    w->rank = i;
}

void destroyRankWall(Wall *walls, int rank) {
    Wall *head = walls;
    Wall *bef = NULL;
    while (walls && walls->rank != rank) {
        bef = walls;
        walls = walls->suiv;
    }
    if (walls) {
        if (bef) {
            bef->suiv = walls->suiv;
        }
        else {
            head = walls->suiv;
        }
        free(walls);
    }
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