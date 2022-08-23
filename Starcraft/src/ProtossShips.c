#include "ProtossShips.h"
#include <stdlib.h>

void regenerateShield(protossShip *ship){

    if(ship->protossType == PHOENIX){

        if(ship->protossShield + PHOENIX_SHIELD_REGENERATE_RATE > PHOENIX_SHIELD){

            ship->protossShield = PHOENIX_SHIELD;
        }
        else{

            ship->protossShield += PHOENIX_SHIELD_REGENERATE_RATE;
        }
    }
    else{

        if(ship->protossShield + CARRIER_SHIELD_REGENERATE_RATE > CARRIER_SHIELD){

            ship->protossShield = CARRIER_SHIELD;
        }
        else{

            ship->protossShield += CARRIER_SHIELD_REGENERATE_RATE;
        }
    }
}