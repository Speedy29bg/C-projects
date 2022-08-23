#ifndef PISTOL_H_
#define PISTOL_H_

#include "Defines.h"

typedef struct Pistol Pistol;

Pistol* pistolInit( int pistolId, int pistolDamagePerRound, int pistolClipSize, int pistolRemainingAmmo);
void setCurrClipBullets(Pistol** pistol , int bulletCount);
void setRemainingAmmo(Pistol** pistol, int currClipSize);
int getPistolType(Pistol* pistol);
int getDamagePerRound(Pistol * pistol);
void reload(Pistol** pistol);
bool isRemainingAmmoEmpty(Pistol * pistol);

#endif /* PISTOL_H_ */
