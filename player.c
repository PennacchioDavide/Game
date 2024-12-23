#include <raylib.h>

#include "player.h"


const float playerSpeed = 6.5;
 

Player *playerCreation() {
    Player *player = (Player *) malloc(sizeof(Player));
    player->rect.height = 30;
    player->rect.width = 30;
    player->rect.x = 100;
    player->rect.y = 100;
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