#include "carrier.h"
#include <stdlib.h>
#include <stdio.h>

protossShip *initCarrier(){

    protossShip *newCarrier = (protossShip*)malloc(sizeof(protossShip));

    newCarrier->protossHealth = CARRIER_HEALTH;
    newCarrier->protossDamage = CARRIER_DAMAGE;
    newCarrier->protossShield = CARRIER_SHIELD;
    newCarrier->protossType = CARRIER;

    return newCarrier;
}

bool carrierTurn(protossShip *attackingShip, Vector *terranFleet, int id){

    terranShip *shipToAttack = vectorGet(terranFleet, vectorGetSize(terranFleet) - 1);
    int maxNumOfAttacks = returnNumberOFAttacks(attackingShip);

    for(int attacks = 0; attacks < maxNumOfAttacks; attacks++){

        if(carrierAttack(attackingShip, shipToAttack)){

            printf("%s with ID: %d killed enemy airship with ID: %zu\n"
                        ,"Carrier",id, vectorGetSize(terranFleet)-1);

            vectorDelete(terranFleet,vectorGetSize(terranFleet)-1);

            if(vectorIsEmpty(terranFleet)){

                return true;
            }

            shipToAttack = vectorGet(terranFleet, vectorGetSize(terranFleet)-1);
        }
    }
    
    regenerateShield(attackingShip);
    return false;
}

int returnNumberOFAttacks(protossShip *carrierShip){

    if(carrierShip->protossHealth == CARRIER_HEALTH){

        return MAX_INTERCEPTORS;
    }
    else{

        return DAMAGED_STATUS_INTERCEPTORS;
    }
}

bool carrierAttack(protossShip *attackingShip, terranShip *targetShip){

    targetShip->terranHealth -= attackingShip->protossDamage;
    if(targetShip->terranHealth <= 0){

        return true;
    }
    else{

        return false;
    }
}