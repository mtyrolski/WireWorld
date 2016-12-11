#pragma once

#include <SFML/Graphics.hpp>

class DrawbleObject sealed
{
protected:
	sf::Sprite m_sprite;
	sf::RenderWindow *m_window;

	void setCenter();
public:
	DrawbleObject(sf::RenderWindow *window,sf::Vector2f pos);
	void Draw();
};
