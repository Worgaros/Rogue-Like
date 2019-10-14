#pragma once

#include <vector>

class Map
{
	public:
		Map(int posX, int posY);
		const unsigned int map_length = 32;
		const unsigned int map_width = 17;
		void print_map();
		int check_obstacle(int NewPosX, int NewPosY);
		void set_new_player_pos(int obstacle, int posX, int posY, int newPosx, int newPosY);
		void visible_trap(bool showTrap);
	
	private:
		std::vector<std::vector<char> > map_;
};
