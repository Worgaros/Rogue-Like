#include "game.h"
#include "map.h"
#include "player.h"
#include "potion.h"
#include "trap.h"

void run()
{
	bool isRunning = true;
	Player playerStats = Player();
	Map map = Map(playerStats.posX, playerStats.posY);
	Potion potionStats = Potion();
	Trap trapStats = Trap();
	int heal = potionStats.heal_player();
	int damage = trapStats.make_damages();
	
	while (isRunning)
	{
		map.print_map();
		playerStats.print_player_stats();
		bool showTrap = playerStats.calc_new_pos();
		map.visible_trap(showTrap);
		int obstacle = map.check_obstacle(playerStats.newPosX, playerStats.newPosY);
		map.set_new_player_pos(obstacle, playerStats.posX, playerStats.posY, playerStats.newPosX, playerStats.newPosY);
		playerStats.set_new_position(obstacle, heal, damage);
		playerStats.death(isRunning);
	}
}
