#include "player.h"

/// <summary>
/// default constructor
/// </summary>
player::player()
{
	std::cout << "Player has been created" << std::endl;
	setupPlayer();
}

/// <summary>
/// default deconstructor (not needed but i like including it)
/// </summary>
player::~player()
{
	std::cout << "Player has been destroyed" << std::endl;
}

/// <summary>
/// The render method for the player sprite
/// </summary>
/// <param name="t_window">window object for rendering</param>
void player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}

/// <summary>
/// Moves the player and keeps the player within bounds
/// </summary>
void player::movePlayer(sf::RectangleShape t_object[])
{
	sf::Vector2f movement{ 0.f,0.f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y += -m_speed;
		m_sprite.setTextureRect(sf::IntRect(12, 256, 57, 62));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += m_speed;
		m_sprite.setTextureRect(sf::IntRect(12, 13, 57, 62));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x += -m_speed;
		m_sprite.setTextureRect(sf::IntRect(12, 91, 57, 62));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += m_speed;
		m_sprite.setTextureRect(sf::IntRect(12, 177, 57, 62));
	}
	/// <summary>
	/// for diagonal movement it is divided by 1.5 so diagonals arent faster to walk on
	/// </summary>
	if ((movement.x == m_speed && movement.y == m_speed) ||
		(movement.x == -m_speed && movement.y == -m_speed) ||
		(movement.x == m_speed && movement.y == -m_speed) ||
		(movement.x == -m_speed && movement.y == m_speed))
	{
		movement /= sqrt(2.0f);
	}

	
	m_location += movement; // apply the movement

	sf::FloatRect intersection;

	for (int i = 0; i < 5; i++)
	{
		if (t_object[i].getGlobalBounds().intersects(m_sprite.getGlobalBounds(), intersection))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				m_location += sf::Vector2f(intersection.width + m_playerSize.x, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				m_location += sf::Vector2f(-intersection.width - m_playerSize.x, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				m_location += sf::Vector2f(0, intersection.height + m_playerSize.y);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				m_location += sf::Vector2f(0, -intersection.height - m_playerSize.y);
		}
	}

	/// <summary>
	/// boundary checking
	/// </summary>
	if (m_location.x <= 0)
	{
		m_location.x = 1.f;
	}
	else if (m_location.x >= SCREEN_WIDTH - m_playerSize.x)
	{
		m_location.x = SCREEN_WIDTH - m_playerSize.x - 1.f;
	}
	if (m_location.y <= 0)
	{
		m_location.y = 1.f;
	}
	else if (m_location.y >= SCREEN_HEIGHT - m_playerSize.y)
	{
		m_location.y = SCREEN_HEIGHT - m_playerSize.y - 1.f;
	}
	m_sprite.setPosition(m_location);
}

/// <summary>
/// Setup the default character sprite
/// </summary>
void player::setupPlayer()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\player.png"))
	{
		std::cout << "Couldnt load player texture" << std::endl;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(12, 13, 57, 66));
	m_sprite.setPosition(m_location);
}

sf::Vector2f player::returnPosition()
{
	return m_location;
}

sf::Vector2f player::returnAim()
{
	return m_mousePos;
}

void player::fireWeapon(sf::Event t_event, sf::RenderWindow& t_window)
{
	m_mousePos = t_window.mapPixelToCoords({ t_event.mouseMove.x, t_event.mouseMove.y });
}
