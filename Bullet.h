/// <summary>
/// bullet class used to control all interactions involving the bullet
/// </summary>
#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Globals.h"

class Bullet
{
public:
	Bullet(sf::Vector2f t_startPos, sf::Vector2f t_aim);
	~Bullet();

	void render(sf::RenderWindow& t_window);
	void moveBullet();
private:
	const unsigned int BULLET_SIZE{ 2 }; // total size of the bullet
	sf::Vector2f m_location; // current location of the bullet
	sf::CircleShape m_body; // visible part of the bullet
	sf::Vector2f m_displacement; // speed and direction the bullet will travel at
	float m_speed{ 4 }; // speed the bullet will travel at
};

