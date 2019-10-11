#pragma once

class Player
{
	public:
		int posX = 1;
		int posY = 1;
		int newPosX = 1;
		int newPosY = 1;
		char userInput = ' ';
		Player();
		void take_damages(int damage);
		void take_heal(int heal);
		void set_new_position(int obstacle, int heal, int damage);
		void calc_new_pos();
		void print_player_stats();
		void death(bool& isRunning);
	
	private:
		int health_points_ = 3;
};