#pragma once

#include <SFML/Graphics.hpp>

class DrawbleObject
{
protected:
	sf::RectangleShape m_shape;

	sf::RenderWindow *m_window;

	void setCenter();
public:
	DrawbleObject(sf::RenderWindow *window);
	void Draw();
};
