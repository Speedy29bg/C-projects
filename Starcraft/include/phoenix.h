#ifndef PHOENIX_H
#define PHOENIX_H

#include"ProtossShips.h"
#include"TerranShips.h"
#include"Vector.h"
#include<stdbool.h>

protossShip *initPhoenix();
bool phoenixTurn(protossShip *attackingShip, Vector *terranFleet, int id);
bool phoenixAttack(protossShip *attacingkShip, terranShip *targetShip);

#endif //PHOENIX_H