#include <raylib.h>

typedef struct Player {
    Rectangle rect;
}Player;

Player *playerCreation();
void playerMovement(Player *player);