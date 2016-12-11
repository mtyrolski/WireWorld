#include "Cell.h"

void Cell::changeTexture()
{
	switch (m_state)
	{
	case EMPTY: break;
	case HEAD: break;
	case TAIL: break;
	case GUIDE: break;
	}
}

Cell::Cell(sf::Vector2i id,sf::RenderWindow *window) : DrawbleObject(window), m_id(id) , m_state(EMPTY)
{
}

void Cell::SetState(short value)
{
	m_state = value;

	changeTexture();
}

short Cell::GetState()
{
	return m_state;
}

void Cell::Init(sf::Vector2f dimensions)
{
	Cell::m_dimensions = dimensions;
}
