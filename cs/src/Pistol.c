#include "Pistol.h"
#include <stdlib.h>
#include <stdbool.h>

struct Pistol {
    enum PistolType pistolType;
    int damagePerRound;
    int clipSize;
    int currClipBullets;
    int remainingAmmo;
};

Pistol* pistolInit( int pistolId, int pistolDamagePerRound, int pistolClipSize, int pistolRemainingAmmo){
    Pistol* currPistol = (Pistol*)malloc(sizeof(Pistol));

    currPistol->pistolType = pistolId;
    currPistol->damagePerRound = pistolDamagePerRound;
    currPistol->clipSize = pistolClipSize;
    currPistol->currClipBullets = pistolClipSize;
    currPistol->remainingAmmo = pistolRemainingAmmo;

    return currPistol;
}

void setCurrClipBullets(Pistol** pistol , int bulletCount){
    (*pistol)->currClipBullets = bulletCount;
}

void setRemainingAmmo(Pistol** pistol, int currClipSize){
    (*pistol)->remainingAmmo=currClipSize;
}

int getPistolType(Pistol* pistol){
    return pistol->pistolType;
}

int getDamagePerRound(Pistol * pistol){
    return pistol->damagePerRound;
}


void reload(Pistol** pistol){

    if ((*pistol)->remainingAmmo >= (*pistol)->clipSize) {
        (*pistol)->remainingAmmo -= (*pistol)->clipSize;
        (*pistol)->currClipBullets += (*pistol)->clipSize;

    }else{

        (*pistol)->remainingAmmo = 0;
        (*pistol)->currClipBullets += (*pistol)->remainingAmmo;

    }
}

bool isRemainingAmmoEmpty(Pistol * pistol){

    if(pistol->remainingAmmo == 0){
        return false;
    }
    return true;
}



