#ifndef BATTLE_CRUSER_H
#define BATTLE_CRUSER_H

#include"ProtossShips.h"
#include"TerranShips.h"
#include"Vector.h"
#include<stdbool.h>

typedef struct protossShip protossShip;

terranShip *initBattleCruser();
bool battleCruserTurn(terranShip *attackingShip, Vector *protossFleet, int id);
bool attackBattleCruser(terranShip *airShip, protossShip *airShipToAttack);

#endif //BATTLE_CRUSER_H