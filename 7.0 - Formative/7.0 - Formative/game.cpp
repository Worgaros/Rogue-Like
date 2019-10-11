#include "game.h"
#include "map.h"
#include "player.h"
#include "potion.h"
#include "trap.h"

void run()
{
	bool isRunning = true;
	Map map = Map();
	Player player = Player();
	Potion potion = Potion();
	Trap trap = Trap();
	int heal = potion.heal_player();
	int damage = trap.make_damages();
	while (isRunning)
	{
		map.print_map();
		player.print_player_stats();
		player.calc_new_pos();
		int obstacle = map.check_obstacle(player.newPosX, player.newPosY);
		map.set_new_player_pos(obstacle, player.posX, player.posY, player.newPosX, player.newPosY);
		player.set_new_position(obstacle, heal, damage);
		player.death(isRunning);
	}
}