#include "map.h"
#include <iostream>

Map::Map()
{
}

void Map::print_map()
{
	system("Color 08");
	for (int i = 0; i < map_.size(); i++)
	{
		for (int j = 0; j < map_[i].size(); j++)
		{
			std::cout << map_[i][j];
		}
		std::cout << "\n";
	}
}

int Map::check_obstacle(int newPosX, int newPosY)
{
	switch (map_[newPosY][newPosX])
	{
		case Sprite::ground:
		{
			return 1;
		}

		case Sprite::potion :
		{
			return 2;
		}

		case Sprite::trap:
		{
			return 3;
		}

		default:
		{
			return 4;
		}
	}
}

void Map::set_new_player_pos(int obstacle, int posX, int posY , int newPosX, int newPosY)
{
	system("cls");
	switch (obstacle)
	{
		case 1:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}

		case 2:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}

		case 3:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}

	}
}