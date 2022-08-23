#include "BattleField.h"
#include "Defines.h"
#include "phoenix.h"
#include "carrier.h"
#include "viking.h"
#include "battleCruser.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr) {
    
  size_t terranNumbers = strlen(terranFleetStr);
  vectorInit(&battleField->terranFleet, terranNumbers);


  /*
    v - Viking
    b - Battle Cruiser
  */

  char shipInitials;
  terranShip *newBattleCruiser;
  terranShip *newViking;


  for (size_t i = 0; i < terranNumbers; i++)
  {
    shipInitials = terranFleetStr[i];
    switch (shipInitials)
    {
      case 'b':
        
        /* calls init BATTLE CRUISER*/
        newBattleCruiser = initBattleCruser();
        vectorPush(&battleField->terranFleet, newBattleCruiser);
        break;
      case 'v':
        
        /* calls init VIKING */          
        newViking = initViking();
        vectorPush(&battleField->terranFleet, newViking);
        break;

      default:
        printf("Wrong ship initials input\n");
        break;  
    
    }
  }
  
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr) {

  size_t protossNumbers = strlen(protossFleetStr);
  vectorInit(&battleField->protossFleet, protossNumbers);
  /*
  p - Phoenix
  c - Carrier
  */

  char shipInitials;
  protossShip *newPhoenix;
  protossShip *newCarrier;
  for (size_t i = 0; i < protossNumbers; i++)
  {
    shipInitials = protossFleetStr[i];

    switch (shipInitials)
    {
      case 'p':
        
        /* calls init Phoenix*/
        
        newPhoenix = initPhoenix();
        vectorPush(&battleField->protossFleet, newPhoenix);
        break;
      case 'c':
        
        /* calls init Carrier */
        
        newCarrier = initCarrier();
        vectorPush(&battleField->protossFleet, newCarrier);
        break;

      default:
        printf("Wrong ship initials input\n");
        break;  
    
    }
  }
}

void startBattle(BattleField *battleField) {

  while (true) {

    if (processTerranTurn(battleField)) {

      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField)) {

      printf("PROTOSS has won!\n");
      break;
    }
  }
}

bool processTerranTurn(BattleField *battleField) {

  int fleetSize;
  fleetSize = vectorGetSize(&battleField->terranFleet);
  terranShip *attackingShip;
  for (int i = 0; i < fleetSize; i++) {

    attackingShip = vectorGet(&battleField->terranFleet, i);

    if (attackingShip->terranType == VIKING) {

      if (vikingTurn(attackingShip, &battleField->protossFleet, i)) {
        
        return true;
      }
    } 
    else {

      if (battleCruserTurn(attackingShip, &battleField->protossFleet, i)) {
        
        return true;
      }
    }
  }
  protossShip *targerShip = vectorGet(&battleField->protossFleet, vectorGetSize(&battleField->protossFleet)-1);
  printf("Last Protoss AirShip with ID: %zu has %d health left and %d shield left\n"
  ,vectorGetSize(&battleField->protossFleet) - 1, targerShip->protossHealth, targerShip->protossShield);

  return false;
}

bool processProtossTurn(BattleField *battleField) {
  int fleetSize;
  fleetSize= vectorGetSize(&battleField->protossFleet);
  protossShip * attackingShip;
  for(int i = 0 ; i < fleetSize;i++){

    attackingShip = vectorGet(&battleField->protossFleet, i);

    if(attackingShip->protossType == PHOENIX){

      if(phoenixTurn(attackingShip,&battleField->terranFleet,i)){

        return true;
      }
    }
    else{

      if(carrierTurn(attackingShip,&battleField->terranFleet,i)){

        return true;
      }
    }
  }

  terranShip *targetShip = vectorGet(&battleField->terranFleet, vectorGetSize(&battleField->terranFleet)-1);
  printf("Last Terran AirShip with ID: %zu has %d health left\n"
  , vectorGetSize(&battleField->terranFleet)-1,targetShip->terranHealth);
  return false;
}

void deinit(BattleField *battleField) {

  if(!vectorIsEmpty(&battleField->terranFleet)){

    int size = vectorGetSize(&battleField->terranFleet);
    terranShip * shipToDelete;

    for(int i = 0; i < size; i++){
      
      shipToDelete = vectorGet(&battleField->terranFleet,i);
      free(shipToDelete);
    }
  }

  if(!vectorIsEmpty(&battleField->protossFleet)){

      int size = vectorGetSize(&battleField->protossFleet);
      protossShip * shipToDelete;

      for(int i = 0; i < size; i++){

        shipToDelete = vectorGet(&battleField->protossFleet,i);
        free(shipToDelete);
      }
  }
  vectorFree(&battleField->terranFleet);
  vectorFree(&battleField->protossFleet);

}