#include "DrawbleObject.h"

void DrawbleObject::setCenter()
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0f, m_sprite.getGlobalBounds().height / 2.0f);
}

DrawbleObject::DrawbleObject(sf::RenderWindow * window):m_window(window)
{
}

void DrawbleObject::Draw()
{
	m_window->draw(m_sprite);
}
