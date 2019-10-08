#include "game.h"
#include "map.h"
#include "player.h"
#include "potion.h"

void run()
{
	bool isRunning = true;
	Map map = Map();
	Player player = Player();
	Potion potion = Potion();
	int heal = potion.heal_player();
	while (isRunning)
	{
		map.print_map();
		player.print_health();
		player.calc_new_pos();
		int obstacle = map.check_obstacle(player.newPosX, player.newPosY);
		map.set_new_player(obstacle, player.posX, player.posY, player.newPosX, player.newPosY);
		player.set_new_position(obstacle, heal);
	}
}
