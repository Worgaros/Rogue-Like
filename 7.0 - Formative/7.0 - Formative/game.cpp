#include "game.h"
#include "map.h"
#include "player.h"

void run()
{
	bool isRunning = true;
	Map map = Map();
	Player player = Player();
	while (isRunning)
	{
		system("cls");
		map.print_map();
		player.calc_new_pos();
		bool isFree = map.check_postion(player.newPosX, player.newPosY);
		map.set_new_player(isFree, player.posX, player.posY, player.newPosX, player.newPosY);
		player.set_new_position(isFree);
	}
}