#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "walls.h"
#include "screens.h"

bool start = false;
bool levelSelector = false;

void sceneFunction() {
    if (!start){
        startScreen(&start);
    }
    else if (!levelSelector){
        levelSelectorScreen(&levelSelector);
    }
}

void startScreen(bool *start) {
    HideCursor();
    DrawText("Test Game", 425, 300, 40, RAYWHITE);
    DrawText("To start the game click SPACE", 350, 400, 25, RAYWHITE);
    if (IsKeyPressed(KEY_SPACE)) {
        *start = true;
    }
}

void levelSelectorScreen(bool *levelSelector) {
    ShowCursor();
    Rectangle rect1 = {200, 300, 100, 100};
    DrawRectangleRec(rect1, RAYWHITE);
    DrawText("1", 200, 300, 40, BLACK);
    if (IsKeyPressed(KEY_SPACE)) {
        *levelSelector = true;
    }

}