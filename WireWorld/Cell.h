#pragma once

#include <SFML/Graphics.hpp>
#include "DrawbleObject.h"

class Cell sealed : public DrawbleObject
{
	const sf::Vector2i m_id;

	static sf::Vector2f m_dimensions;

	static enum
	{
		EMPTY = 0,
		HEAD = 1,
		TAIL = 2,
		GUIDE = 3
	};

	short m_state;

	void updateTexture();

public:
	Cell(sf::Vector2i id, sf::RenderWindow *window);

	void SetState(short value);
	short GetState();

	static void Init(sf::Vector2f dimensions,sf::Vector2i ammount, sf::RenderWindow *window);

	static std::vector<Cell> cells;
};