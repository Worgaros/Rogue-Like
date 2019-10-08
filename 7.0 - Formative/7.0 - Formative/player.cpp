#include "player.h"
#include <iostream>

Player::Player()
{}

void Player::take_damages(int damage)
{
	health_points_ -= damage;
}

void Player::take_heal(int heal)
{
	
	health_points_ += heal;
}

void Player::set_new_position(int obstacle, int heal)
{

	if(userInput == 'w' || userInput == 's')
	{
		switch (obstacle)
		{
			case 1:
			{		
				posY = newPosY;
			}

			case 2:
			{
				posY = newPosY;
				take_heal(heal);
			}

			/*case 3:
			{
				posY = newPosY;
				take_damages(damage);
			}*/
		}

	}

	else if (userInput == 'a' || userInput == 'd')
	{
		switch (obstacle)
		{
		case 1:
		{
			posY = newPosY;
		}

		case 2:
		{
			posY = newPosY;
			take_heal(heal);
		}

		/*case 3:
		{
			posY = newPosY;
			take_damages(damage);
		}*/
		}
	}

	else
	{
		newPosX = posX;
		newPosY = posY;
	}
}

void Player::calc_new_pos()
{
	std::cin >> userInput;
	
	if (userInput == 'w')
	{
		newPosY -= 1;
	}

	if (userInput == 's')
	{
		newPosY += 1;
	}
	
	if (userInput == 'd')
	{
		newPosX += 1;
	}
	
	if (userInput == 'a')
	{
		newPosX -= 1;
	}
}

void Player::print_health()
{
	std::cout << health_points_;
}