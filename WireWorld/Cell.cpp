#include "Cell.h"

sf::Vector2i Cell::m_ammount;
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
		m_shape.setFillColor(sf::Color::Cyan);
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
	Cell::m_ammount = ammount;
	Cell::m_dimensions  = dimensions;
	for (size_t j = 0; j < ammount.y; j++)
	{
		for (size_t i = 0; i < ammount.x; i++)
		{
			cells.emplace_back(sf::Vector2i(i, j), window);
		}
	}
}

size_t Cell::computeNeighborHeads()
{
	return
			//j-1
			(( exist(m_id.x - 1 + m_ammount.x*(m_id.y - 1)) && Cell::cells[m_id.x - 1 + m_ammount.x*(m_id.y - 1)].GetState() == Cell::HEAD ? 1 : 0) +
			(exist(m_id.x + m_ammount.x*(m_id.y - 1)) && Cell::cells[m_id.x + m_ammount.x*(m_id.y - 1)].GetState() == Cell::HEAD ? 1 : 0) +
			(exist(m_id.x + 1 + m_ammount.x*(m_id.y - 1)) && Cell::cells[m_id.x + 1 + m_ammount.x*(m_id.y - 1)].GetState() == Cell::HEAD ? 1 : 0) +
			//j	
			(exist(m_id.x - 1 + m_ammount.x*m_id.y) && Cell::cells[m_id.x - 1 + m_ammount.x*m_id.y].GetState() == Cell::HEAD ? 1 : 0) +
			(exist(m_id.x + 1 + m_ammount.x*m_id.y) && Cell::cells[m_id.x + 1 + m_ammount.x*m_id.y].GetState() == Cell::HEAD ? 1 : 0) +
			//j+1
			(exist(m_id.x - 1 + m_ammount.x*(m_id.y + 1)) && Cell::cells[m_id.x - 1 + m_ammount.x*(m_id.y + 1)].GetState() == Cell::HEAD ? 1 : 0) +
			(exist(m_id.x + m_ammount.x*(m_id.y + 1)) && Cell::cells[m_id.x + m_ammount.x*(m_id.y + 1)].GetState() == Cell::HEAD ? 1 : 0) +
			(exist(m_id.x + 1 + m_ammount.x*(m_id.y + 1)) && Cell::cells[m_id.x + 1 + m_ammount.x*(m_id.y + 1)].GetState() == Cell::HEAD ? 1 : 0));
}


bool Cell::exist(size_t number)
{
	return (number >= 0 && number < m_ammount.x*m_ammount.y);
}

void Cell::ConfirmUpdate()
{
	m_state = nextValue;
	updateTexture();
}

void Cell::PrepareUpdate()
{
	switch (m_state)
	{
	case EMPTY:	break;

	case HEAD:
	{
		SetState(Cell::TAIL);
		break;
	}
	case TAIL:
	{
		SetState(Cell::GUIDE);
		break;
	}
	case GUIDE:
	{
		if (computeNeighborHeads() == 1 || computeNeighborHeads() == 2)
		{
			SetState(Cell::HEAD);
		}
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

	m_shape.setPosition(id.x*m_dimensions.x,id.y*m_dimensions.y);

	nextValue = Cell::EMPTY;
}


void Cell::SetState(short value)
{
	nextValue = value;
}



void Cell::ChangeState()
{
	SetState((m_state+1 > Cell::GUIDE ? Cell::HEAD : m_state+1));
	ConfirmUpdate();
	updateTexture();
}

void Cell::Clear()
{
	m_state = Cell::EMPTY;
	nextValue = Cell::EMPTY;

	updateTexture();
}


short Cell::GetState()
{
	return m_state;
}

void Cell::Init(sf::Vector2f dimensions, sf::Vector2i ammount, sf::RenderWindow *window)
{
	fillVector(dimensions,ammount,window);
}
