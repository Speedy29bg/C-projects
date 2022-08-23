#ifndef STARCRAFT_TERRANSHIPS_H
#define STARCRAFT_TERRANSHIPS_H
#include"Defines.h"
#include<stdbool.h>
#include"ProtossShips.h"


typedef struct terranShip{

    int terranHealth;
    int terranDamage;
    int terranCount;
    enum AirShipType terranType;

}terranShip;

#endif //STARCRAFT_TERRANSHIPS_H
