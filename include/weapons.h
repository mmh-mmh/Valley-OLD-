#ifndef WEAPONS_H
#define WEAPONS_H
#include "valley.h"

typedef enum{SWORD_TYPE}WeaponType;
typedef struct //status of the weapon
{
	WeaponType type;
	int damage;
	int durability;
}Weaponstats; 

#endif
