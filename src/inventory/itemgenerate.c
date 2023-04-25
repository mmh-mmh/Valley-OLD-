
#include "inventory.h"

Inventory * genSword(int damage, int durability, char *name_sword)
{
	Inventory* item=malloc(sizeof(Inventory));
	item->type=Weapon_Type;
	strcpy(item->name,name_sword);
	item->mainItems.weapon=malloc(sizeof(Weapon));
	item->weapon.damage=damage;
	item->weapon.durability=durability;
	return item;
}

