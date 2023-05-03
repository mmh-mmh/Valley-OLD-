#include "valley.h"

MobStruct * genMonster(int health,int attack,char skin,int movement,int y, int x)
{
	MobStruct * monster;
	monster=malloc(sizeof(MobStruct*));
	monster->health=health;
	monster->attack=attack;
	monster->movement=movement;
	monster->skin=skin;
	monster->coordinates.x=x;
	monster->coordinates.y=y;
	return monster;
}

