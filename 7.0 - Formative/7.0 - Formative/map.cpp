#include <iostream>
#include <vector>
#include "map.h"
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

	map_[5][29] = Sprite::potion;
	map_[11][2] = Sprite::potion;

	map_[posY][posX] = Sprite::player;

}

void Map::print_map()
{
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
			level_2();
			return 4;
		}

		case Sprite::key:
		{
			collectedKeys_ += 1;
			openDoor();
			return 5;
		}

		case Sprite::princess:
		{
			return 6;
		}
		
		default:
		{
			return 7;
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

		case 5:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}
	}
}

void Map::visible_trap(int showTrap)
{
	if (showTrap == 1)
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
	}
}

void Map::level_2()
{
	map_length = 26;
	map_width = 26;
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

	map_[1][1] = Sprite::potion;
	map_[24][1] = Sprite::potion;
	map_[24][24] = Sprite::potion;
	map_[1][24] = Sprite::potion;

	map_[1][12] = Sprite::invisibleTrap;
	map_[6][12] = Sprite::invisibleTrap;
	map_[12][1] = Sprite::invisibleTrap;
	map_[12][6] = Sprite::invisibleTrap;
	map_[12][18] = Sprite::invisibleTrap;
	map_[12][24] = Sprite::invisibleTrap;
	map_[18][12] = Sprite::invisibleTrap;
	map_[24][12] = Sprite::invisibleTrap;

	map_[5][5] = Sprite::rock;
	map_[5][6] = Sprite::rock;
	map_[5][7] = Sprite::rock;
	map_[6][5] = Sprite::rock;//haut gauche
	map_[6][7] = Sprite::rock;
	map_[7][5] = Sprite::rock;
	map_[7][7] = Sprite::rock;

	map_[5][17] = Sprite::rock;
	map_[5][18] = Sprite::rock;
	map_[5][19] = Sprite::rock;
	map_[6][17] = Sprite::rock;//haut droit
	map_[6][19] = Sprite::rock;
	map_[7][17] = Sprite::rock;
	map_[7][19] = Sprite::rock;

	map_[17][5] = Sprite::rock;
	map_[17][7] = Sprite::rock;
	map_[18][5] = Sprite::rock;
	map_[18][7] = Sprite::rock;//bas gauche
	map_[19][5] = Sprite::rock;
	map_[19][6] = Sprite::rock;
	map_[19][7] = Sprite::rock;

	map_[17][17] = Sprite::rock;
	map_[17][19] = Sprite::rock;
	map_[18][17] = Sprite::rock;
	map_[18][19] = Sprite::rock;//bas droit
	map_[19][17] = Sprite::rock;
	map_[19][18] = Sprite::rock;
	map_[19][19] = Sprite::rock;

	map_[11][11] = Sprite::rock;
	map_[11][12] = Sprite::rock;
	map_[11][13] = Sprite::rock;
	map_[12][11] = Sprite::rock;//centre
	map_[12][13] = Sprite::rock;
	map_[13][11] = Sprite::rock;
	map_[13][12] = Sprite::rock;
	map_[13][13] = Sprite::rock;

	map_[6][6] = Sprite::key;
	map_[18][6] = Sprite::key;
	map_[6][18] = Sprite::key;
	map_[18][18] = Sprite::key;

	map_[12][12] = Sprite::princess;
	
	map_[15][12] = Sprite::player;
}

void Map::openDoor()
{
	if(collectedKeys_ == 4)
	{
		system("cls");
		std::cout << "Congratulation hero (" << Sprite::player << "), you took the 4 keys and the passage leading to the princess opened.\n\n";
		system("pause");
		system("cls");
		map_[13][12] = Sprite::ground;
	}
}