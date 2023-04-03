/// <summary>
/// @author David Strikaitis
/// @date 22/03/2023
///
/// </summary>

#include "Game.h"

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT, 32U }, "Shooter Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupBackground();

	m_gameProps[1].initProp({80,120}, {100,100});
	m_gameProps[2].initProp({ 120,80 }, { 500,150 });
	m_gameProps[3].initProp({ 80,60 }, { 300,300 });
	m_gameProps[4].initProp({ 80,120 }, { 120,550 });
	m_gameProps[0].initProp({ 80,120 }, { 600,400 });

}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseMoved == newEvent.type)
		{
			playerOne.fireWeapon(newEvent, m_window);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type)
		{
			if (sf::Mouse::Left == newEvent.mouseButton.button)
			{
				m_shooting = false;
			}
		}
		if (sf::Event::MouseButtonPressed == newEvent.type)
		{
			if (sf::Mouse::Left == newEvent.mouseButton.button)
			{
				m_shooting = true;
			}
		}

	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	sf::RectangleShape rectangles[5];
	for (int i = 0; i < 5; i++)
		rectangles[i] = m_gameProps[i].returnRectangle();
	playerOne.movePlayer(rectangles); // called here for smoother movement
	m_bulletManager.moveBullets();
	shooting();
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_backgroundSprite);
	m_window.draw(m_welcomeMessage);
	m_bulletManager.render(m_window);
	for (int i = 0; i < 5; i++)
		m_gameProps[i].render(m_window);
	playerOne.render(m_window);
	m_window.display();
}

/// <summary>
/// Setup for the background sprite and texture
/// </summary>
void Game::setupBackground()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\floor.png"))
	{
		std::cout << "Couldnt load background texture" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("Shooter game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

void Game::shooting()
{
	if (m_cooldownTime <= m_shootCooldown)
	{
		if (m_shooting)
		{
			m_bulletManager.spawnNewBullet(playerOne);
			m_shootCooldown = 0;
		}
	}
	m_shootCooldown++;
}
