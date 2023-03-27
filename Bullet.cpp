#include "Bullet.h"

Bullet::Bullet(sf::Vector2f t_startPos, sf::Vector2f t_aim)
{
	std::cout << "New Bullet created" << std::endl;
	m_body.setRadius(static_cast<float>(BULLET_SIZE));
	m_body.setFillColor(sf::Color::Red);
	m_body.setPosition(t_startPos);
	m_location = t_startPos;

	m_displacement = t_aim - m_location;
	m_displacement /= std::sqrtf(m_displacement.x * m_displacement.x + m_displacement.y * m_displacement.y);
	m_displacement = m_displacement * m_speed;
}

Bullet::~Bullet()
{
	std::cout << "Bullet has been destroyed" << std::endl;
}

void Bullet::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void Bullet::moveBullet()
{
	m_location += m_displacement;
	m_body.setPosition(m_location);
}
