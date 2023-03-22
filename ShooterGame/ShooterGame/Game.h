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

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_backgroundTexture; // texture for the dungeon background
	sf::Sprite m_backgroundSprite; // sprite for the dungeon background
	bool m_exitGame; // control exiting game

	player playerOne; // playerCharacter
};

#endif // !GAME_HPP

