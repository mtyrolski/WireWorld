#include "DrawbleObject.hpp"

void DrawbleObject::setCenter()
{
	m_shape.setOrigin(m_shape.getGlobalBounds().width / 2.0f, m_shape.getGlobalBounds().height / 2.0f);
}

DrawbleObject::DrawbleObject(sf::RenderWindow * window):m_window(window)
{
}

void DrawbleObject::Draw()
{
	m_window->draw(m_shape);
}
