#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

typedef struct Player {
    Rectangle rect;
}Player;

typedef struct Wall Wall;

Player *playerCreation();
void playerMovement(Player *player);
void playerWallCollision(Player *player, Wall *walls);
void showPlayer(Player *player);

#endif