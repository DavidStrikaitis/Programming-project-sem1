#include "ZombieEnemy.h"

ZombieEnemy::ZombieEnemy()
{
	m_body.setFillColor(sf::Color::Red);
	m_body.setSize({ 30,30 });
	m_body.setOrigin({ 15,15 });

	m_maxHealthBar.setFillColor(sf::Color::Red);
	m_maxHealthBar.setSize({ 40,5 });
	m_maxHealthBar.setOrigin({ 20,22.5 });
	m_healthBar.setFillColor(sf::Color::Green);
	m_healthBar.setSize({ 40,5 });
	m_healthBar.setOrigin({ 20,22.5 });
}

ZombieEnemy::~ZombieEnemy()
{
}

void ZombieEnemy::initZombie(sf::Vector2f t_spawn)
{
	m_location = t_spawn;
	m_body.setPosition(m_location);
	m_maxHealthBar.setPosition(m_location);
	m_healthBar.setPosition(m_location);
	m_health = (rand() % 80) + 20;
	m_maxHealth = m_health;
	m_alive = true;
}

void ZombieEnemy::render(sf::RenderWindow& t_window)
{
	if (m_alive)
	{
		t_window.draw(m_body);
		t_window.draw(m_maxHealthBar);
		t_window.draw(m_healthBar);
	}
}

bool ZombieEnemy::getAlive()
{
	return m_alive;
}

void ZombieEnemy::calculateDirection(sf::Vector2f t_target)
{
	m_targetLocation = t_target;
	m_displacement = t_target - m_location;
	m_displacement /= std::sqrtf(m_displacement.x * m_displacement.x + m_displacement.y * m_displacement.y);
	m_displacement = m_displacement * m_speed;
}

void ZombieEnemy::moveZombie()
{
	if (m_location.x <= m_targetLocation.x + 10.0f && m_location.x >= m_targetLocation.x - 10.0f &&
		m_location.y <= m_targetLocation.y + 10.0f && m_location.y >= m_targetLocation.y - 10.0f)
	{
		m_displacement = m_displacement * -25.0f;
	}
	m_location += m_displacement;
	m_body.setPosition(m_location);
	m_maxHealthBar.setPosition(m_location);
	m_healthBar.setPosition(m_location);
}

sf::Vector2f ZombieEnemy::getPosition()
{
	return m_location;
}

sf::RectangleShape ZombieEnemy::getBody()
{
	return m_body;
}

void ZombieEnemy::setspeed(int t_speed)
{
	m_speed = t_speed;
}

int ZombieEnemy::returnSpeed()
{
	return m_speed;
}

void ZombieEnemy::applyDamage(int t_bulletDamage)
{
	m_health -= t_bulletDamage;
	std::cout << m_health << std::endl;
	float x = m_health/m_maxHealth;
	m_healthBar.setScale(sf::Vector2f( x,1 ));

	if (m_health <= 0)
	{
		m_alive = false;
		m_location = sf::Vector2f(-500, -500);
		m_body.setPosition(m_location);
	}
}
