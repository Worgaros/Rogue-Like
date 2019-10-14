#include "map.h"
#include <iostream>
#include <vector>
#include "sprite.h"

Map::Map(int posX, int posY)
{
	map_ = std::vector<std::vector<char> >(map_width, std::vector<char>(map_length));
	for (int i = 0; i < map_.size(); i++)
	{
		for (unsigned int j = 0; j < map_[i].size(); j++)
		{
			map_[i][j] = Sprite::ground;
		}
	}

	for (unsigned int i = 0; i < map_length; i++)
	{
		map_[0][i] = Sprite::wall;
		map_[map_width - 1][i] = Sprite::wall;
	}

	for (unsigned int i = 0; i < map_width; i++)
	{
		map_[i][0] = Sprite::wall;
		map_[i][map_length - 1] = Sprite::wall;
	}
	
	for (int i = 13; i <= 15; i++)
	{
		map_[i][31] = Sprite::portal;
		map_[i][31] = Sprite::portal;		
		map_[i][31] = Sprite::portal;
	}

	for (int i = 1; i <= 27; i++)
	{
		map_[4][i] = Sprite::wall;
	}
	for (int i = 1; i <= 27; i++)
	{
		map_[5][i] = Sprite::wall;
	}
	for (int i = 1; i <= 27; i++)
	{
		map_[6][i] = Sprite::wall;
	}

	for (int i = 4; i <= 30; i++)
	{
		map_[10][i] = Sprite::wall;
	}
	for (int i = 4; i <= 30; i++)
	{
		map_[11][i] = Sprite::wall;
	}
	for (int i = 4; i <= 30; i++)
	{
		map_[12][i] = Sprite::wall;
	}

	map_[2][6] = Sprite::invisibleTrap;
	map_[1][12] = Sprite::invisibleTrap;
	map_[3][12] = Sprite::invisibleTrap;
	map_[2][21] = Sprite::invisibleTrap;
	map_[7][23] = Sprite::invisibleTrap;
	map_[9][23] = Sprite::invisibleTrap;
	map_[8][17] = Sprite::invisibleTrap;
	map_[7][16] = Sprite::invisibleTrap;
	map_[8][15] = Sprite::invisibleTrap;
	map_[9][13] = Sprite::invisibleTrap;
	map_[8][7] = Sprite::invisibleTrap;
	map_[13][7] = Sprite::invisibleTrap;
	map_[14][7] = Sprite::invisibleTrap;
	map_[14][13] = Sprite::invisibleTrap;
	map_[15][13] = Sprite::invisibleTrap;
	map_[13][19] = Sprite::invisibleTrap;
	map_[14][19] = Sprite::invisibleTrap;
	map_[14][24] = Sprite::invisibleTrap;
	map_[15][24] = Sprite::invisibleTrap;
	map_[14][26] = Sprite::invisibleTrap;
	map_[13][28] = Sprite::invisibleTrap;
	map_[15][28] = Sprite::invisibleTrap;
	

	map_[posY][posX] = Sprite::player;

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

		case Sprite::potion:
		{
			return 2;
		}

		case Sprite::invisibleTrap:
		{
			return 3;
		}

		case Sprite::trap:
		{
			return 3;
		}

		case Sprite::portal:
		{
				/*changer map*/
			return 4;
		}

		default:
		{
			return 5;
		}
	}
}

void Map::set_new_player_pos(int obstacle, int posX, int posY, int newPosX, int newPosY)
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

void Map::visible_trap(bool showTrap)
{
	if (showTrap)
	{
		for (int i = 0; i < map_.size(); i++)
		{
			for (unsigned int j = 0; j < map_[i].size(); j++)
			{
				if (map_[i][j] == Sprite::invisibleTrap)
				{
					map_[i][j] = Sprite::trap;
				}
			}
		}
		
		system("cls");
		print_map();
	}
}