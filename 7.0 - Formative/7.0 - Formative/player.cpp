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

void Player::set_new_position(int obstacle, int heal, int damage)
{
	if(userInput == 'w' || userInput == 's')
	{
		switch (obstacle)
		{
			case 1:
			{		
				posY = newPosY;
				break;
			}

			case 2:
			{
				posY = newPosY;
				take_heal(heal);
				break;
			}

			case 3:
			{
				posY = newPosY;
				take_damages(damage);
				break;
			}

			default:
			{
				newPosY = posY;
			}
		}
		newPosX = posX;
		newPosY = posY;
	}

	else if (userInput == 'a' || userInput == 'd')
	{
		switch (obstacle)
		{
			case 1:
			{
				posX = newPosX;
				break;
			}

			case 2:
			{
				posX = newPosX;
				take_heal(heal);
				break;
			}

			case 3:
			{
				posX = newPosX;
				take_damages(damage);
				break;
			}

			default:
			{
				
			}
		}
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

void Player::print_player_stats()
{
	std::cout << health_points_ << "\n";
}

void Player::death(bool& isRunning)
{
	if (health_points_ <= 0)
	{
		system("cls");
		std::cout << "Game Over !\n";
		isRunning = false;
	}
}