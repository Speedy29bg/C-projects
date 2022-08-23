#ifndef VIKING_H
#define VIKING_H

#include"ProtossShips.h"
#include"TerranShips.h"
#include"Vector.h"
#include<stdbool.h>

typedef struct protossShip protossShip;

terranShip *initViking();
bool vikingTurn(terranShip *attackingShip, Vector *protossFleet, int id);
terranShip *setVikingAttack(terranShip *vikingShip, protossShip *targetShip);
bool attackViking(terranShip *attackingShip, protossShip *targetShip);

#endif //VIKING_H