// class for the shooter enemy
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Globals.h"
#include"gameProp.h"

#pragma once
class shooterEnemy
{
public:
	shooterEnemy();
	~shooterEnemy();
	void initEnemy(sf::Vector2f t_spawn, gameProp t_boxes[], sf::Vector2f t_playerPos);
private:
	sf::Vector2f m_location{ -200,-200 }; // location of the enemy
	sf::RectangleShape m_body; // visible body of the enemy
	int m_health{ 0 }; // health of the enemy
	int m_maxHealth{ 0 }; // maxiumum health of the enemy
	bool m_alive{ false }; // is the enemy alive/active
	sf::Vector2f m_displacement; // displacement vector the enemy moves along
	float m_speed{ 0 };// speed at which the enemy travels

	sf::RectangleShape m_maxHealthBar; // background red health bar that will display the amount of max health
	sf::RectangleShape m_healthBar;    // green health bar showing the enemies current health

	void pickClosestBoxPos(gameProp t_boxes[], sf::Vector2f t_playerPos);
};

