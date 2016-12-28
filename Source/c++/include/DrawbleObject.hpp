#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


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
