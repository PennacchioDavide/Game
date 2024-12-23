#include <raylib.h>
#include <stdlib.h>

#include "player.h"


const int screenWidth = 1080;
const int screenHeight = 720;


int main() {

    InitWindow(screenWidth, screenHeight, "Game");
    HideCursor();
    SetTargetFPS(60);

    Player *player = playerCreation();

    while (!WindowShouldClose()) {

        // Player Movement
        playerMovement(player);

        // Drawing on Screen
        BeginDrawing();

            ClearBackground(BLACK);
            DrawRectangleRec(player->rect, RAYWHITE);

        EndDrawing();
    }

    free(player);

    CloseWindow();

    return 0;
}