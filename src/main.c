#include "valley.h"


int main()
{
	mainSetup();
	
	PlayerStruct * player = playerSetup(PLAYER_START_POSITION_Y, PLAYER_START_POSITION_X); 
	
	char ** map = mapSetup(MAP_HEIGHT, MAP_WIDTH);
	
	WINDOW * gameWindow = gameWindowSetup(GAME_WINDOW_HEIGHT, GAME_WINDOW_WIDTH, GAME_WINDOW_POSITION_Y, GAME_WINDOW_POSITION_X);
	
	
	char input;
	
	while ( (input = getch()) != 'a')
	{
		
		//change the player position
		handlePlayerInput(player, input, map);

		//draw map arround the player, in the window's boundaries
		drawMapInGameWindow(gameWindow, map, player);
	}
	
	endwin();
}


int mainSetup()
{
	srand(time(NULL));
	initscr();
	cbreak();
	noecho();
	curs_set(0);
}