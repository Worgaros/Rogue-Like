#include "map.h"
#include <iostream>

Map::Map()
{
}

void Map::print_map()
{
	system("Color 08");
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
}
