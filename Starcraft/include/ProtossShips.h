#ifndef STARCRAFT_PROTOSSSHIPS_H
#define STARCRAFT_PROTOSSSHIPS_H
#include"Defines.h"
#include<stdbool.h>
#include"TerranShips.h"

typedef struct protossShip{

    int protossHealth;
    int protossShield;
    int protossDamage;
    enum AirShipType protossType;

}protossShip;

typedef struct terranShip terranShip;

void regenerateShield(protossShip *ship);




#endif //STARCRAFT_PROTOSSSHIPS_H
