#include <raylib.h>
#include <stdlib.h>

#include "player.h"
#include "walls.h"


const float playerSpeed = 6.5;


Player *playerCreation() {
    Player *player = (Player *) malloc(sizeof(Player));
    player->rect.height = 40;
    player->rect.width = 40;
    player->rect.x = 540;
    player->rect.y = 360;
}

void playerMovement(Player *player) {
    if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
        player->rect.y -= playerSpeed;
    }
    if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
        player->rect.y += playerSpeed;
    }
    if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
        player->rect.x += playerSpeed;
    }
    if (IsKeyDown(KEY_A) &&!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
        player->rect.x -= playerSpeed;
    }

    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D)) {
        player->rect.y -= playerSpeed * 0.707;
        player->rect.x += playerSpeed * 0.707;
    }
    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A)) {
        player->rect.y -= playerSpeed * 0.707;
        player->rect.x -= playerSpeed * 0.707;
    }
    if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D)) {
        player->rect.y += playerSpeed * 0.707;
        player->rect.x += playerSpeed * 0.707;
    }
    if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A)) {
        player->rect.y += playerSpeed * 0.707;
        player->rect.x -= playerSpeed * 0.707;
    }
}


//Temporary
void playerWallCollision(Player *player, Wall *walls) {
    Wall *tmp = walls;
    while (tmp) {
        if (CheckCollisionRecs(player->rect, tmp->rect)) {
            destroyRankWall(walls, tmp->rank);
            break;
        }
        tmp = tmp->suiv;
    }
}