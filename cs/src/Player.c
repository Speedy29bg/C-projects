#include "Player.h"
#include <stdlib.h>

typedef struct {
    int health;
    int armor;
} PlayerVitalData;

struct Player{
    PlayerVitalData playerData;
    Pistol* pistol;
    int playerId;
};


Player* playerInit(int health, int armor, int id){
    Player * currPlayer = (Player*)malloc(sizeof(Player));

    currPlayer->playerData.health = health;
    currPlayer->playerData.armor = armor;
    currPlayer->playerId = id;

    return currPlayer;
}

void setPistol(Player** player, int pistolId, int pistolDamagePerRound, int pistolClipSize, int pistolRemainingAmmo){
    (*player)->pistol =pistolInit(pistolId,pistolDamagePerRound,pistolClipSize,pistolRemainingAmmo);
}

int getHealth(Player* player){
    return player->playerData.health;
}

int getArmor(Player* player){
    return player->playerData.armor;
}

void setHealth(Player** player, int health){
    (*player)->playerData.health = health;
}

void setArmor(Player** player, int armor){
    (*player)->playerData.armor = armor;
}

bool isAlive(Player* player){
    if(player->playerData.health <= 0){
        return false;
    }
    return true;
}

bool checkForArmor(Player* player){
    if(player->playerData.armor>0){
        return true;
    }
    return false;
}

