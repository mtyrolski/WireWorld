#include "Cell.h"

void Cell::updateTexture()
{
	switch (m_state)
	{
	case EMPTY:
	{
		m_shape.setFillColor(sf::Color::Black);
		break;
	}
	case HEAD:
	{
		m_shape.setFillColor(sf::Color::Red);
		break;
	}
	case TAIL: 
	{
		m_shape.setFillColor(sf::Color::Blue);
		break;
	}
	case GUIDE: 
	{
		m_shape.setFillColor(sf::Color::Yellow);
		break;
	}
	}
}

Cell::Cell(sf::Vector2i id,sf::RenderWindow *window) : DrawbleObject(window), m_id(id) , m_state(EMPTY)
{
	m_shape.setSize(m_dimensions);
	m_shape.setOutlineThickness(m_dimensions.x/10.0f); //10%

	m_shape.setOutlineColor(sf::Color(120, 133, 139)); //Squirrel grey

	updateTexture();

}


void Cell::SetState(short value)
{
	m_state = value;

	updateTexture();
}

short Cell::GetState()
{
	return m_state;
}

void Cell::Init(sf::Vector2f dimensions)
{
	Cell::m_dimensions = dimensions;
}
