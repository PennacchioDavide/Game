#include <raylib.h>
#include <stdlib.h>
#include "player.h"
#include "const.h"
#include <math.h>


int main() {

    InitWindow(screenWidth, screenHeight, "Snake");
    HideCursor();
    SetTargetFPS(60);

    Player *player = playerCreation();
    const float playerDiagonalSpeed = sqrt(player->rect.x * player->rect.x  + player->rect.y * player->rect.y);

    while (!WindowShouldClose()) {

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

        // Drawing on Screen
        BeginDrawing();

            ClearBackground(BLACK);
            DrawRectangleRec(player->rect, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}