#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "walls.h"
#include "screens.h"


bool start = false;
bool levelSelector = false;
bool level1 = false;
bool level2 = false;
bool level3 = false;

void sceneFunction() {
    if (!start){
        startScreen(&start);
    }
    else if (!levelSelector) {
        levelSelectorScreen(&levelSelector);
    }
    else if (!level1) {
        level_1(&level1);
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

void playerWallCollision(Player *player, Wall *walls) {
    Wall *tmp = walls;
    while (tmp) {
        if (CheckCollisionRecs(player->rect, tmp->rect)) {
            if (strcmp(tmp->type, "death") == 0) {
                levelSelector = false;
                free(player);
                freeWalls(tmp);
            }
        }
        tmp = tmp->suiv;
    }
}

void level_1(bool *level1) {

    static Player *player = NULL;
    static Wall *walls = NULL;

    if (player == NULL) {
        player = playerCreation();
    }
    if (walls == NULL) {
        walls = wallCreation(100, 10, 100, 100, "block");
        addLastWall(walls, 10, 100, 800, 600, "win");
        addLastWall(walls, 100, 10, 500, 500, "death");
    }

    playerMovement(player);

    playerWallCollision(player, walls);
    
    showPlayer(player);
    showWalls(walls);
}

void level_2(bool *level2) {
    
}

void level_3(bool *level3) {
    
}

void levelSelectorScreen(bool *levelSelector) {
    ShowCursor();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int x = GetMouseX();
        int y = GetMouseY();
        if (x > 200 && x < 300 && y > 300 && y < 400) {
            level_1(&level1);
            *levelSelector = true;
        }
        if (x > 500 && x < 600 && y > 300 && y < 400) {
            level_2(&level2);
            *levelSelector = true;
        }
        if (x > 800 && x < 900 && y > 300 && y < 400) {
            level_3(&level3);
            *levelSelector = true;
        }
    }
    
    Rectangle rect1 = {200, 300, 100, 100};
    DrawRectangleRec(rect1, RAYWHITE);
    DrawText("1", 245, 330, 40, BLACK);
    if (IsKeyPressed(KEY_SPACE)) {
        *levelSelector = true;
    }

    Rectangle rect2 = {500, 300, 100, 100};
    DrawRectangleRec(rect2, RAYWHITE);
    DrawText("2", 545, 330, 40, BLACK);
    if (IsKeyPressed(KEY_SPACE)) {
        *levelSelector = true;
    }

    Rectangle rect3 = {800, 300, 100, 100};
    DrawRectangleRec(rect3, RAYWHITE);
    DrawText("3", 845, 330, 40, BLACK);
    if (IsKeyPressed(KEY_SPACE)) {
        *levelSelector = true;
    }
}