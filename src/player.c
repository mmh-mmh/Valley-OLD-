#include "valley.h"
#include "inventory.h"

PlayerStruct * playerSetup(int y, int x)
{
	PlayerStruct * player = malloc(sizeof(PlayerStruct));
	player->position.y = y;
	player->position.x = x;
	player->skin = '@';
	player->health = 20;
	player->backpack=malloc(sizeof(Item*)*3);
	
	for(int i=0; i<3; i++)
		player->backpack[i]=malloc(sizeof(Item*));
	//start set
	player->backpack[0]=genSword(1,20,"startersword");
	
	
	return player;
}


int handlePlayerInput(PlayerStruct * player, char input, char ** map)
{
	Position * newPosition;
	newPosition = malloc(sizeof(Position));
	
	switch(input)
	{
		case 'z' :
		case 'Z' :
			newPosition->y = player->position.y - 1;
			newPosition->x = player->position.x;
			playerMove(player, newPosition, map);
			break;
		case 's' :
		case 'S' :
			newPosition->y = player->position.y + 1;
			newPosition->x = player->position.x;
			playerMove(player, newPosition, map);
			break;
		case 'q' :
		case 'Q' :
			newPosition->y = player->position.y;
			newPosition->x = player->position.x - 1;
			playerMove(player, newPosition, map);
			break;
		case 'd' :
		case 'D' :
			newPosition->y = player->position.y;
			newPosition->x = player->position.x + 1;
			playerMove(player, newPosition, map);
			break;
		default :
			break;
			
	}
	return 0;
}


int playerMove(PlayerStruct * player, Position * newPosition, char ** map)
{
	switch (map[newPosition->y][newPosition->x])
	{
		default :
			player->position.y = newPosition->y;
			player->position.x = newPosition->x;
			break;	
		case '#':
		case '&':
			break;
	}
	
	//move(player->position.y, player->position.x);
	return 0;
}
