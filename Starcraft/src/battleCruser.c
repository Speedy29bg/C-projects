#include "battleCruser.h"
#include <stdlib.h>
#include <stdio.h>

terranShip *initBattleCruser(){

    terranShip *newBattleCruser = (terranShip*)malloc(sizeof(terranShip));

    newBattleCruser->terranHealth = BATTLE_CRUSER_HEALTH;
    newBattleCruser->terranDamage = BATTLE_CRUSER_DAMAGE;
    newBattleCruser->terranType = BATTLE_CRUSER;
    newBattleCruser->terranCount = 0;

    return newBattleCruser;
}

bool battleCruserTurn(terranShip *attackingShip, Vector *protossFleet, int id){

    protossShip *targetShip = vectorGet(protossFleet, vectorGetSize(protossFleet)-1);

    if(attackBattleCruser(attackingShip,targetShip)){

        printf("%s with ID: %d killed enemy airship with ID: %zu\n"
                ,"BattleCruser",id, vectorGetSize(protossFleet)-1);

        vectorDelete(protossFleet, vectorGetSize(protossFleet)-1);
    }

    if(vectorIsEmpty(protossFleet)){

        return true;
    }
    
    return false;
}

terranShip *setCruiserAttack(terranShip *attackingShip){

    if(attackingShip->terranCount == YAMATO_CANNON_LOADING_TURNS){

        attackingShip->terranDamage = YAMATO_CANON_DAMAGE;
        attackingShip->terranCount = 0;
    }
    else{

        attackingShip->terranDamage = BATTLE_CRUSER_DAMAGE;
        attackingShip->terranCount++;
    }

    return attackingShip;
}



bool attackBattleCruser(terranShip *attackingShip, protossShip *targetShip)
{
    attackingShip = setCruiserAttack(attackingShip);

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