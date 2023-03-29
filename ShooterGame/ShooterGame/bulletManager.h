/// <summary>
/// does all things related to interaction with the bullet
/// </summary>
#pragma once
#include<iostream>
#include"Bullet.h"
#include"player.h"

class bulletManager
{
public:
	bulletManager();
	~bulletManager();
	
	void spawnNewBullet(player& t_player);
	void render(sf::RenderWindow& t_window);
	void moveBullets();

private:
	Bullet bullets[20]; // array for bullets
	const int MAX_BULLETS{ 20 };
	int bulletAmount{ 0 }; // amount of bullets to be rendered

	void spawnBulletInArrayPos(int t_pos, player& t_player);
};

