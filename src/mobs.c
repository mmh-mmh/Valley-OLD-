#include "valley.h"



MobStruct * genMonster( int health, int attack, char skin)
{
	MobStruct * monster;
	monster=malloc(sizeof(MobStruct*));
	monster->health=health;
	monster->attack=attack;
	monster->skin=skin;

	return monster;
}

MobStruct * Mobselect(int mobtype)
{
	MobStruct * error= NULL;
	if(mobtype==0)
	{
		return genMonster(10,4,'X');
	} else if (mobtype==1)
	{
		return genMonster(5,2,'V');
	}
	return error ;
}
