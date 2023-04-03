/// <summary>
/// collidable object in the scene, enemies will hide behind this
/// </summary>
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Globals.h"

class gameProp
{
public:
	gameProp();
	~gameProp();

	void initProp(sf::Vector2f t_size, sf::Vector2f t_position);
	void render(sf::RenderWindow& t_window);

	sf::RectangleShape returnRectangle();

private:
	sf::RectangleShape m_ObjectRectangle;
	sf::Vector2f m_position;
};

