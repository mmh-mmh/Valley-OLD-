#include "valley.h"


int main()
{
	
	mainSetup();

	/*loading();*/
	
	menuLoop();

	PlayerStruct * player = playerSetup(PLAYER_START_POSITION_Y, PLAYER_START_POSITION_X); 
	
	char ** map = mapSetup(MAP_HEIGHT, MAP_WIDTH);

	mapInmovableGeneration(map);

	char ** mapInmovableSave = saveMap(map);

	mapMovableGeneration(map);
	
	
	WINDOW * gameWindow = gameWindowSetup(GAME_WINDOW_HEIGHT, GAME_WINDOW_WIDTH, GAME_WINDOW_POSITION_Y, GAME_WINDOW_POSITION_X);
	
	
	char input;
	
	while ( (input = getch()) != 'a')
	{
		
		//change the player position
		handlePlayerInput(player, input, map, mapInmovableSave);

		//draw map arround the player, in the window's boundaries
		drawMapInGameWindow(gameWindow, map, player);
	}
	
	endwin();
}


int mainSetup()
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	srand(time(NULL));
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
}

void loading()
{
    printf("\033[8;100;200t"); // ajuste la taille de la fenêtre
    printf("\033[2J"); // nettoie l'écran
    printf("\033[1;31m"); // change la couleur du texte en rouge

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("      V     V    AAAA    L          L     EEEEEEE   Y     Y\n");
    printf("      V     V   A    A   L          L     E         Y   Y \n");
    printf("      V     V  AAAAAAAA  L          L     EEEEE      Y Y  \n");
    printf("       V   V   A      A  L          L     E           Y   \n");
    printf("        V V    A      A  LLLLLLLLL  LLLLL EEEEEEE     Y   \n");

    sleep(5); // pause pendant 5 secondes
	printf("\033[0m"); // remet la couleur du texte à la normale
    printf("\033[2J"); // nettoie l'écran
    printf("\033[0;0H");
}
