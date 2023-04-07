/// <summary>
/// author David Strikaitis 22/03/2023
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include"Globals.h"
#include"player.h"
#include"bulletManager.h"
#include"gameProp.h"
#include"ZombieManager.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void setupBackground();

	void setupFontAndText();
	void shooting();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_backgroundTexture; // texture for the dungeon background
	sf::Sprite m_backgroundSprite; // sprite for the dungeon background
	bool m_exitGame; // control exiting game

	player playerOne; // playerCharacter
	bulletManager m_bulletManager; // manages all interaction with the bullets
	gameProp m_gameProps[5]; // a game prop within the level that is collidable
	bool m_shooting{false}; // checks if the player is shooting
	int m_shootCooldown{ 0 }; // for the time between firing
	int m_cooldownTime{ 12 }; // time between firing

	ZombieManager m_zombieManager; // manages all interaction with the zombie
};

#endif // !GAME_HPP

