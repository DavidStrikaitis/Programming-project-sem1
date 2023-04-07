/// <summary>
/// controls all interaction with the zombie character
/// </summary>
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"ZombieEnemy.h"
#include<cstdlib>
#include<ctime>

class ZombieManager
{
public:
	ZombieManager();
	~ZombieManager();

	void render(sf::RenderWindow& t_window);
	int getAmountAlive();
	void moveZombiesTowardsPlayer(sf::Vector2f t_location);
	void initialiseNewZombie();

private:
	ZombieEnemy zombies[10]; // array of zombies
	int m_zombieAmount{ 10 };  // amount of zombies in game
	sf::Vector2f m_playerLoc; // location of the player
};

