#include "valley.h"

PlayerStruct * playerSetup(int y, int x)
{
	PlayerStruct * player = malloc(sizeof(PlayerStruct));
	player->position.y = y;
	player->position.x = x;
	player->skin = '@';
	player->health = 20;
	player->backpack = malloc(sizeof(Item*)*3);
	
	for(int i=0; i<3; i++)
		player->backpack[i] = malloc(sizeof(Item*));
	//start set
	player->backpack[0] = genSword(1,20,"startersword");
	
	
	return player;
}


int handlePlayerInput(PlayerStruct * player, char input, char ** map, char ** mapInmovableSave)
{
	Position * posDif;
	posDif = malloc(sizeof(Position));
	
	switch(input)
	{
		
		case 'z' :
		case 'Z' :
			posDif->y = - 1;
			posDif->x = 0;
			playerMove(player, posDif, map, mapInmovableSave);
			break;
		case 's' :
		case 'S' :
			posDif->y = + 1;
			posDif->x = 0;
			playerMove(player, posDif, map, mapInmovableSave);
			break;
		case 'q' :
		case 'Q' :
			posDif->y = 0;
			posDif->x = - 1;
			playerMove(player, posDif, map, mapInmovableSave);
			break;
		case 'd' :
		case 'D' :
			posDif->y = 0;
			posDif->x = + 1;
			playerMove(player, posDif, map, mapInmovableSave);
			break;
		default :
			break;
			
	}
	return 0;
}


int playerMove(PlayerStruct * player, Position * posDif, char ** map, char ** mapInmovableSave)
{

	switch (map[player->position.y + posDif->y][player->position.x + posDif->x])
	{
		default :
			player->position.y += posDif->y;
			player->position.x += posDif->x;
			break;	
		case '#':
		case '&':
			break;
		case 'O':
			handleMovable(player, posDif, map, mapInmovableSave);
			break;
	}

	return 0;
}

int handleMovable(PlayerStruct * player, Position * posDiff, char ** map, char ** mapInmovableSave)
{
	Position newMovablePosition;
	Position newPlayerPosition;

	newPlayerPosition.y = player->position.y + posDiff->y;
	newPlayerPosition.x = player->position.x + posDiff->x;

	newMovablePosition.y = newPlayerPosition.y + posDiff->y;
	newMovablePosition.x = newPlayerPosition.x + posDiff->x;

	switch(map[newMovablePosition.y][newMovablePosition.x])
	{
		case '.':
		case ',':
			map[newMovablePosition.y][newMovablePosition.x] = 'O';
			map[newPlayerPosition.y][newPlayerPosition.x] = mapInmovableSave[newPlayerPosition.y][newPlayerPosition.x];

			player->position.y = newPlayerPosition.y;
			player->position.x = newPlayerPosition.x;

			break;

		case '#':
		case '&':
			break;
	}

	return 0;
}