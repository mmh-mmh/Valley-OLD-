#ifndef VALLEY_H
#define VALLEY_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <menu.h>
#include <unistd.h>
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


//main fonctions
int mainSetup();
void loading();

//menu fonctions;
void closeMenu(int numberItems, MENU * menu, ITEM ** items);
int mainMenu(int numberItems, char * choices[]);
void menuLoop();

//player fonctions
PlayerStruct * playerSetup(int y, int x);
int handlePlayerInput(PlayerStruct * player, char input, char ** map, char ** mapInmovableSave);
int playerMove(PlayerStruct * player, Position * newPosition, char ** map, char ** mapInmovableSave);
int handleMovable(PlayerStruct * player, Position * newPlayerPosition, char ** map, char ** mapInmovableSave);

//map fonctions
char ** mapSetup(int height, int width);
int mapInmovableGeneration(char ** map);
int mapMovableGeneration(char ** map);
int drawMapInGameWindow(WINDOW * window, char ** map, PlayerStruct * player);
int mapRandSandGeneration(char ** map);
int mapRandHouseGeneration(char ** map);
int mapRandRockGeneration(char ** map);
int mapRandMovableGeneration(char ** map);
int unblockDoor(char ** map, Position * doorPos);
char ** saveMap(char ** map);

//window fonctions
WINDOW * gameWindowSetup(int height, int width, int y, int x);

#endif
