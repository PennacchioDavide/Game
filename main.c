#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

const int screenWidth = 1080;
const int screenHeight = 720;

int main() {

    InitWindow(screenWidth, screenHeight, "Snake");
    HideCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Drawing on Screen
        BeginDrawing();

            ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}