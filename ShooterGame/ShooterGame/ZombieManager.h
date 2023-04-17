/// <summary>
/// controls all interaction with the zombie character
/// </summary>
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"ZombieEnemy.h"
#include<cstdlib>
#include<ctime>
#include"Bullet.h"
#include"bulletManager.h"

class ZombieManager
{
public:
	ZombieManager();
	~ZombieManager();

	void render(sf::RenderWindow& t_window);
	int getAmountAlive();
	bool moveZombiesTowardsPlayer(sf::Vector2f t_location);
	void initialiseNewZombie();
	void damageZombies(sf::FloatRect bullets[], int bulletDamage[], int t_amountOfBullets, bulletManager& t_bulletManager);

private:
	ZombieEnemy zombies[10]; // array of zombies
	int m_zombieAmount{ 10 };  // amount of zombies in game
	sf::Vector2f m_playerLoc; // location of the player
};

