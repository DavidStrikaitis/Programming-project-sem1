/// <summary>
/// player class controls all actions concerning the player
/// </summary>
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Globals.h"

class player
{
public:
	player();
	~player();

	void render(sf::RenderWindow& t_window);
	void movePlayer(sf::RectangleShape t_object[]);
	void setupPlayer();
	sf::Vector2f returnPosition();
	sf::Vector2f returnAim();
	void fireWeapon(sf::Event t_event, sf::RenderWindow& t_window);
	void damagePlayer();

private:

	sf::Texture m_texture; // texture for the player character
	sf::Sprite m_sprite; // sprite for the player character

	int m_speed{ 4 }; // speed of the player
	sf::Vector2f m_location{ 200,100 }; // location of the player
	sf::Vector2f m_playerSize{ 57,62 }; // the size of the player used for screen bounds check
	sf::Vector2f m_mousePos; // position of the mouse when last firing the weapon
	int m_health{ 10 };       // amount of health the player has
};

