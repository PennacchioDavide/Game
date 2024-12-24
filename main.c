#include <raylib.h>
#include <stdlib.h>

#include "player.h"
#include "walls.h"


const int screenWidth = 1080;
const int screenHeight = 720;


int main() {

    InitWindow(screenWidth, screenHeight, "Test Game");
    HideCursor();
    SetTargetFPS(60);

    Player *player = playerCreation();
    Wall *walls = wallCreation(100, 10, 100, 100, "block");
    addLastWall(walls, 10, 100, 800, 600, "win");
    addLastWall(walls, 100, 10, 500, 500, "death");


    while (!WindowShouldClose()) {

        // Player Movement
        playerMovement(player);
        playerWallCollision(player, walls);

        // Drawing on Screen
        BeginDrawing();

            ClearBackground(BLACK);
            DrawRectangleRec(player->rect, PURPLE);
            showWalls(walls);

        EndDrawing();
    }

    // Free Mallocs
    free(player);
    freeWalls(walls);

    CloseWindow();

    return 0;
}