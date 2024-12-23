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
    if (IsKeyDown(KEY_UP) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) {
        player->rect.y -= playerSpeed;
    }
    if (IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) {
        player->rect.y += playerSpeed;
    }
    if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
        player->rect.x += playerSpeed;
    }
    if (IsKeyDown(KEY_LEFT) &&!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
        player->rect.x -= playerSpeed;
    }

    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) {
        player->rect.y -= playerSpeed * 0.707;
        player->rect.x += playerSpeed * 0.707;
    }
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) {
        player->rect.y -= playerSpeed * 0.707;
        player->rect.x -= playerSpeed * 0.707;
    }
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT)) {
        player->rect.y += playerSpeed * 0.707;
        player->rect.x += playerSpeed * 0.707;
    }
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) {
        player->rect.y += playerSpeed * 0.707;
        player->rect.x -= playerSpeed * 0.707;
    }
}