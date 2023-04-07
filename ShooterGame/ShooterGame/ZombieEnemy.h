/// <summary>
/// zombie enemy
/// </summary>
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class ZombieEnemy
{
public:
	ZombieEnemy();
	~ZombieEnemy();

	void initZombie(sf::Vector2f t_spawn);

	void render(sf::RenderWindow& t_window);
	bool getAlive();
	void calculateDirection(sf::Vector2f t_target);
	void moveZombie();
	sf::Vector2f getPosition();
	sf::RectangleShape getBody();
	void setspeed(int t_speed);
	int returnSpeed();
	void applyDamage(int t_bulletDamage);
	bool inLevel();
private:
	sf::Vector2f m_location; // location of the zombie
	sf::Vector2f m_targetLocation; // place the zombie wants to go to

	bool m_alive{ false }; // check if the zombie is alive
	sf::RectangleShape m_body; // the visible part of the enemy
	float m_speed{ 3.0f }; // speed of the enemies
	sf::Vector2f m_displacement; // direction the zombie must travel in
	int m_health{ 0 }; // amount of health the enemy zombie has
	int m_maxHealth;   // maxiumum amount of health
	bool m_inLevel{ false }; // check if the zombie is in the level bounds,
							 //this is done so that it only walks straight after spawning

	sf::RectangleShape m_maxHealthBar; // full health bar displayed behind actual health
	sf::RectangleShape m_healthBar;    // health bar that you can see

};

