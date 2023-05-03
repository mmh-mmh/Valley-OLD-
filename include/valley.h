#ifndef VALLEY_H
#define VALLEY_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "inventory.h"

#define MAP_HEIGHT 41
#define MAP_WIDTH 81

#define GAME_WINDOW_HEIGHT 21
#define GAME_WINDOW_WIDTH 51
#define GAME_WINDOW_POSITION_Y 5
#define GAME_WINDOW_POSITION_X 20

#define PLAYER_START_POSITION_Y MAP_HEIGHT/2
#define PLAYER_START_POSITION_X MAP_WIDTH/2


typedef struct Position
{
	int x;
	int y;
} Position;

typedef struct PlayerStruct
{
	Position position;
	char skin;
	int health;
	Item ** backpack;
} PlayerStruct;

typedef struct
{
	int health;
	int attack;
	char skin;
	int movement;
	Position coordinates;
}MobStruct;


//main fonctions
int mainSetup();

//player fonctions
PlayerStruct * playerSetup(int y, int x);
int handlePlayerInput(PlayerStruct * player, char input, char ** map);
int playerMove(PlayerStruct * player, Position * newPosition, char ** map);

//map fonctions
char ** mapSetup(int height, int width);
int drawMapInGameWindow(WINDOW * window, char ** map, PlayerStruct * player);
char ** mapRandSandSetup(char ** map);
char ** mapRandHouseSetup(char ** map,Position Housepos);
char ** mapRandRockSetup(char ** map);
int unblockDoor(char ** map, Position * doorPos);
//Mob functions
MobStruct * genMonster(int health,int attack,char skin,int movement,int y,int x);
void addmonster(char ** map, int width,int height,Position *housepos);

//window fonctions
WINDOW * gameWindowSetup(int height, int width, int y, int x);

#endif
