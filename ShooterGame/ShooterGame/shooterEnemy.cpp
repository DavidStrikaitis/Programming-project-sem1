#include "shooterEnemy.h"

shooterEnemy::shooterEnemy()
{
	m_body.setFillColor(sf::Color(255, 255, 0, 255));
	m_body.setSize({ 30.0f,30.0f });
	m_body.setOrigin({ 15.0f,15.0f });

	m_maxHealthBar.setFillColor(sf::Color::Red);
	m_maxHealthBar.setSize({ 40,5 });
	m_maxHealthBar.setOrigin({ 20,22.5 });
	m_healthBar.setFillColor(sf::Color::Green);
	m_healthBar.setSize({ 40,5 });
	m_healthBar.setOrigin({ 20,22.5 });
}

shooterEnemy::~shooterEnemy()
{
}

void shooterEnemy::initEnemy(sf::Vector2f t_spawn, gameProp t_boxes[], sf::Vector2f t_playerPos)
{
	m_location = t_spawn;
	m_body.setPosition(m_location);
	m_maxHealthBar.setPosition(m_location);
	m_healthBar.setPosition(m_location);
	m_speed = static_cast<float>(rand() % 4) + 2;
	m_health = (rand() % 80) + 20;
	m_maxHealth = m_health;
	pickClosestBoxPos(t_boxes, t_playerPos);
	m_alive = true;
}

void shooterEnemy::pickClosestBoxPos(gameProp t_boxes[], sf::Vector2f t_playerPos)
{
	int closestBoxNo = 0;
	sf::Vector2f distanceToBox{ 1000,1000 };
	for (int i = 0; i < 5; i++)
	{
		distanceToBox.x = m_location.x - t_boxes[i].returnRectangle().getPosition().x;
		distanceToBox.x = sqrt(distanceToBox.x * distanceToBox.x);
		distanceToBox.y = m_location.y - t_boxes[i].returnRectangle().getPosition().y;
		distanceToBox.y = sqrt(distanceToBox.y * distanceToBox.y);
		if (distanceToBox.x + distanceToBox.y <
			t_boxes[closestBoxNo].returnRectangle().getPosition().x + t_boxes[closestBoxNo].returnRectangle().getPosition().y)
		{
			closestBoxNo = i;
		}
	}
	sf::Vector2f boxSize = t_boxes[closestBoxNo].returnRectangle().getSize();
	sf::Vector2f boxPos = t_boxes[closestBoxNo].returnRectangle().getPosition();

	for (int i = 0; i < 4; i++)
	{

	}
}
