#include <raylib.h>
#include <stdlib.h>

#include "player.h"
#include "walls.h"


const int screenWidth = 1080;
const int screenHeight = 720;


int main() {

    InitWindow(screenWidth, screenHeight, "Game");
    HideCursor();
    SetTargetFPS(60);

    Player *player = playerCreation();
    Wall *walls = wallCreation(100, 10, 100, 100);


    while (!WindowShouldClose()) {

        // Player Movement
        playerMovement(player);

        // Drawing on Screen
        BeginDrawing();

            ClearBackground(BLACK);
            DrawRectangleRec(player->rect, RED);
            showWalls(walls);

        EndDrawing();
    }

    // Free Mallocs
    free(player);
    freeWalls(walls);

    CloseWindow();

    return 0;
}