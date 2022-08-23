#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>

#include "Pistol.h"
#include "Defines.h"

typedef struct Player Player;

Player* playerInit(int health, int armor, int id);
void setPistol(Player** player, int pistolId, int pistolDamagePerRound, int pistolClipSize, int pistolRemainingAmmo);
int getHealth(Player* player);
int getArmor(Player* player);
void setHealth(Player** player, int health);
void setArmor(Player** player, int armor);
bool isAlive(Player* player);
bool checkForArmor(Player* player);

#endif /* PLAYER_H_ */
