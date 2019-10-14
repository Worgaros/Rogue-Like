#pragma once
#include <iostream>

class Player
{
	public:
		int posX = 1;
		int posY = 2;
		int newPosX = posX;
		int newPosY = posY;
		std::string userInput;
		Player();
		void take_damages(int damage);
		void take_heal(int heal);
		void set_new_position(int obstacle, int heal, int damage);
		bool calc_new_pos();
		void print_player_stats();
		void death(bool& isRunning);
		bool ask_take_potion(int heal);
	
	private:
		int health_points_ = 3;
};
