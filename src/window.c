#include "valley.h"

WINDOW * gameWindowSetup(int height, int width, int y, int x)
{
	WINDOW * newGameWindow = malloc(sizeof(WINDOW));
	newGameWindow = newwin(height, width, y, x);
	box(newGameWindow, 0, 0);
	return newGameWindow;
	
}
