#include "phoenix.h"
#include <stdlib.h>
#include <stdio.h>

protossShip *initPhoenix(){

    protossShip *newPhoenix = (protossShip*)malloc(sizeof(protossShip));

    newPhoenix->protossHealth = PHOENIX_HEALTH;
    newPhoenix->protossDamage = PHOENIX_DAMAGE;
    newPhoenix->protossShield = PHOENIX_SHIELD;
    newPhoenix->protossType = PHOENIX;

    return  newPhoenix;
}

bool phoenixTurn(protossShip *attackingShip, Vector *terranFleet, int id) {

    terranShip *shipToAttack = vectorGet(terranFleet, vectorGetSize(terranFleet) - 1);

    if (phoenixAttack(attackingShip, shipToAttack)) {

        printf("%s with ID: %d killed enemy airship with ID: %zu\n"
                    , "Phoenix", id, vectorGetSize(terranFleet) - 1);

        vectorDelete(terranFleet, vectorGetSize(terranFleet) - 1);

        if (vectorIsEmpty(terranFleet)) {

            return true;
        }
    }
    return false;
}

bool phoenixAttack(protossShip *attackingShip, terranShip *targetShip){

    targetShip->terranHealth -= attackingShip->protossDamage;

    regenerateShield(attackingShip);

    if(targetShip->terranHealth <= 0){

        return true;
    }
    else{

        return false;
    }
}

