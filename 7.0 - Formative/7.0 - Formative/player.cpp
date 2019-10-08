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

void Player::set_new_position(bool isFree)
{

	if(userInput == 'w' && isFree)
	{
		posY = newPosY;
	}

	else if (userInput == 's' && isFree)
	{
		posY = newPosY;
	}

	else if (userInput == 'a' && isFree)
	{
		posX = newPosX;
	}

	else if (userInput == 'd' && isFree)
	{
		posX = newPosX;
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