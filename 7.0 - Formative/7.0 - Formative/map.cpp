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

bool Map::check_postion(int NewPosX, int NewPosY)
{
	if (map_[NewPosY][NewPosX] == ' ')
	{
		return true;
	}

	else
	{
		return false;
	}
}

void Map::set_new_player(bool isFree, int posX, int posY , int newPosX, int newPosY)
{
	if (isFree)
	{
		std::swap(map_[posY][posX], map_[newPosY][newPosX]);
	}
}