#include "Cell.h"

sf::Vector2f Cell::m_dimensions;
std::vector<Cell> Cell::cells;

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



void Cell::fillVector(sf::Vector2f dimensions, sf::Vector2i ammount, sf::RenderWindow *window)
{
	m_dimensions=dimensions;

	for (size_t j = 0; j < ammount.y; j++)
	{
		for (size_t i = 0; i < ammount.x; i++)
		{
			cells.emplace_back(sf::Vector2i(i, j), window);
		}
	}
}

Cell::Cell(sf::Vector2i id,sf::RenderWindow *window) : DrawbleObject(window), m_id(id) , m_state(EMPTY)
{
	m_shape.setSize(m_dimensions);
	m_shape.setOutlineThickness(m_dimensions.x/10.0f); //10%

	m_shape.setOutlineColor(sf::Color(120, 133, 139)); //Squirrel grey

	updateTexture();

	m_shape.setPosition(id.x*m_dimensions.x,id.y*m_dimensions.y);
}


void Cell::SetState(short value)
{
	m_state = value;

	updateTexture();
}

void Cell::ChangeState()
{
	SetState((m_state+1 > Cell::GUIDE ? Cell::EMPTY : m_state+1));
}

short Cell::GetState()
{
	return m_state;
}

void Cell::Init(sf::Vector2f dimensions, sf::Vector2i ammount, sf::RenderWindow *window)
{
	fillVector(dimensions,ammount,window);
}
