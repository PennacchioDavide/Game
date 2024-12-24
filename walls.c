#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "walls.h"


Wall *wallCreation(float width, float height, float x, float y, char *type) {
    Wall *wall = (Wall *) malloc(sizeof(Wall));
    wall->type = type;
    wall->rect.height = height;
    wall->rect.width = width;
    wall->rect.x = x;
    wall->rect.y = y;
    wall->suiv = NULL;
    return wall;
}

void addLastWall(Wall *walls, float width, float height, float x, float y, char *type){
    Wall *w = wallCreation(width, height, x, y, type);
    while (walls->suiv != NULL) {
        walls = walls->suiv;
    }
    walls->suiv = w;
}

void showWalls(Wall *walls) {
    Wall *tmp = walls;
    while (tmp) {
        if (strcmp(tmp->type, "block") == 0) {
            DrawRectangleRec(tmp->rect, RAYWHITE);
        }
        else if(strcmp(tmp->type, "death") == 0) {
            DrawRectangleRec(tmp->rect, RED);
        }
        else if(strcmp(tmp->type, "win") == 0) {
            DrawRectangleRec(tmp->rect, GREEN);
        }
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