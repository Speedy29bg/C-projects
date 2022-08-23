#include "viking.h"
#include <stdlib.h>
#include <stdio.h>

terranShip *initViking(){

    terranShip *newViking = (terranShip*)malloc(sizeof(terranShip));

    newViking->terranHealth = VIKING_HEALTH;
    newViking->terranDamage = VIKING_DAMAGE;
    newViking->terranType = VIKING;

    return newViking;
}

terranShip *setVikingAttack(terranShip *vikingShip, protossShip *targetShip){

    if(targetShip->protossType == PHOENIX){

        vikingShip->terranDamage = VIKING_DAMAGE*2;
    }
    else{

        vikingShip->terranDamage = VIKING_DAMAGE;
    }

    return vikingShip;
}

bool vikingTurn(terranShip *attackingShip, Vector *protossFleet, int id) {

    protossShip *shipToAttack = vectorGet(protossFleet, vectorGetSize(protossFleet) - 1);

    if (attackViking(attackingShip, shipToAttack)) {

        printf("%s with ID: %d killed enemy airship with ID: %zu\n"
                    , "Viking", id, vectorGetSize(protossFleet) - 1);
        vectorDelete(protossFleet, vectorGetSize(protossFleet) - 1);

        if (vectorIsEmpty(protossFleet)) {

            return true;
        }
    }

    return false;
}

bool attackViking(terranShip *attackingShip, protossShip* targetShip)
{
    attackingShip = setVikingAttack(attackingShip,targetShip);

    if(targetShip->protossShield  < attackingShip->terranDamage){

        targetShip->protossHealth -= (attackingShip->terranDamage - targetShip->protossShield);
        targetShip->protossShield = 0;
    }
    else{

        targetShip->protossShield -= attackingShip->terranDamage;
    }

    if(targetShip->protossHealth <= 0){

        return true;
    }
    else{

        return false;
    }
}

