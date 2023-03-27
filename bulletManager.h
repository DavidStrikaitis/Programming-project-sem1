/// <summary>
/// does all things related to interaction with the bullet
/// </summary>
#pragma once
#include<iostream>
#include"Bullet.h"

class bulletManager
{
private:
	bulletManager();
	~bulletManager();


public:
	Bullet bullets[20]; // array for bullets
	const int MAX_BULLETS{ 20 }; 
	int bulletAmount{ 0 }; // amount of bullets to be rendered
};

