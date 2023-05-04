#include "valley.h"
#include <math.h>
char ** mapSetup(int height, int width)
{	
	char ** map;
	map = malloc(sizeof(char*) * height);
	Position *Housepos=NULL;
	for(int i = 0; i < height; i++)
	{
		map[i] = malloc(sizeof(char*) * width);
		
	}
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height-1 || j == 0 || j == width-1)
			{
				map[i][j] = '#';
			}
			else
			{
				map[i][j] = '.';
			}
		}
	}
	
	map = mapRandSandSetup(map);
	map = mapRandRockSetup(map);
	map = mapRandHouseSetup(map);

	return map;
}


int drawMapInGameWindow(WINDOW * gameWindow, char ** map, PlayerStruct * player)
{
	Position mapStartPos;
	mapStartPos.y = player->position.y - (GAME_WINDOW_HEIGHT / 2);
	mapStartPos.x = player->position.x - (GAME_WINDOW_WIDTH / 2);
	
	Position mapPos;
	
	for (int i = 1; i <= GAME_WINDOW_HEIGHT - 2; i++)
	{
		for (int j = 1; j <= GAME_WINDOW_WIDTH - 2; j++)
		{
			mapPos.y = mapStartPos.y + i;
			mapPos.x = mapStartPos.x + j;
			
			if (mapPos.y >= 0 && mapPos.y < MAP_HEIGHT && mapPos.x >= 0 && mapPos.x < MAP_WIDTH)
			{
				mvwprintw(gameWindow, i, j, "%c", map[mapPos.y][mapPos.x]);
			}
			else
			{
				mvwprintw(gameWindow, i, j, " ");
			}
		}
	}

	mvwprintw(gameWindow, GAME_WINDOW_HEIGHT/2, GAME_WINDOW_WIDTH/2, "%c", player->skin);

	wresize(gameWindow, GAME_WINDOW_HEIGHT, GAME_WINDOW_WIDTH);
	box(gameWindow, 0, 0);
	wrefresh(gameWindow);
	
	return 0;
}



char ** mapRandSandSetup(char ** map)
{
	
	int proba = 5;
	int chance = 100;
	
	for (int y = 0 ; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (rand() % chance < proba && map[y][x] == '.')
			{
				map[y][x] = ',';
			}
		}
	}
	return map;
}

char ** mapRandRockSetup(char ** map)
{

	int proba = 1;
	int chance = 300;
	
	for (int y = 0 ; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			
			if (rand() % chance < proba && map[y][x] == '.')
			{
				map[y][x] = '&';
			}
		}
	}
	return map;	
} 

char ** mapRandHouseSetup(char ** map)
{
	int houseSize = 11;
	int houseHeight = houseSize;
	int houseWidth = houseSize*2;
	int houseY = (rand() % (MAP_HEIGHT - (houseHeight + 3))) + 2;
	int houseX = (rand() % (MAP_WIDTH - (houseWidth + 3))) + 2;
	Position doorPos;
	
	switch (rand()%4)
	{
		case 0:
			doorPos.x = houseX + houseWidth/2;
			doorPos.y = houseY;
			break;
		case 1:
			doorPos.x = houseX + houseWidth/2;
			doorPos.y = houseY + houseHeight-1;
			break;
		case 2:
			doorPos.x = houseX;
			doorPos.y = houseY + houseHeight/2;
			break;
		case 3:
			doorPos.x = houseX + houseWidth-1;
			doorPos.y = houseY + houseHeight/2;
			break;
	}
	
	for (int y = houseY; y < houseY + houseHeight; y++)
	{
		for(int x = houseX; x < houseX + houseWidth; x++)
		{
			if(x == doorPos.x && y == doorPos.y)
			{
				map[y][x] = ' ';
				unblockDoor(map, &doorPos);
			}
			else if (y == houseY || y == houseY + houseHeight - 1 || x == houseX || x == houseX + houseWidth - 1)
			{
				map[y][x] = '#';
			}
			else
			{
				map[y][x] = ' ';
			}
		}
	}

	return map;
}

int unblockDoor(char ** map, Position * doorPos)
{
	for(int y = (doorPos->y - 1); y <= (doorPos->y + 1); y++)
	{
		for(int x = (doorPos->x - 1); x <= (doorPos->x + 1); x++)
		{
			if(map[y][x] == '&')
			{
				map[y][x] = '.';
			}
		}
	}

	return 0;
}
