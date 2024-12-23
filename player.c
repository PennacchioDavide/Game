#include "player.h"
#include <raylib.h>
#include <stdlib.h>

// Creation snake, augmentation queue, 

Player *playerCreation() {
    Player *player = (Player *) malloc(sizeof(Player));
    player->rect.height = 30;
    player->rect.width = 30;
    player->rect.x = 100;
    player->rect.y = 100;
}