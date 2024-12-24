#include <raylib.h>
#include <stdlib.h>

#include "player.h"
#include "walls.h"
#include "screens.h"


const int screenWidth = 1080;
const int screenHeight = 720;


int main() {

    InitWindow(screenWidth, screenHeight, "Test Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(BLACK);

            sceneFunction();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}