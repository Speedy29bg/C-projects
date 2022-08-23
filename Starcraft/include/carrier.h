#ifndef CARRIER_H
#define CARRIER_H

#include"ProtossShips.h"
#include"TerranShips.h"
#include"Vector.h"
#include<stdbool.h>

protossShip *initCarrier();
bool carrierTurn(protossShip *attackingShip, Vector *terranFleet, int id);
bool carrierAttack(protossShip *attackingShip, terranShip *targetShip);
int returnNumberOFAttacks(protossShip *carrierShip);

#endif //CARRIER_H