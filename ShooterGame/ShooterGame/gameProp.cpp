#include "gameProp.h"

gameProp::gameProp()
{
}

gameProp::~gameProp()
{
}

void gameProp::initProp(sf::Vector2f t_size, sf::Vector2f t_position)
{
	m_position = t_position;
	m_ObjectRectangle.setFillColor(sf::Color::Black);
	m_ObjectRectangle.setSize(t_size);
	m_ObjectRectangle.setPosition(m_position);
}

void gameProp::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_ObjectRectangle);
}

sf::RectangleShape gameProp::returnRectangle()
{
	return m_ObjectRectangle;
}
