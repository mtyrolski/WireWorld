#include "ViewControl.h"

const float ViewControl::moveValue = 2;
const float ViewControl::zoomValue = 2;
sf::View ViewControl::m_view;
Window *ViewControl::m_window;


void ViewControl::Init(Window* window, sf::Vector2f windowDimensions)
{
	ViewControl::m_view.setSize(windowDimensions);
	m_window = window;
}

void ViewControl::Zoom(short value)
{
	switch (value)
	{
	case ZOOM:
	{
		m_view.zoom(ViewControl::zoomValue);
		break;
	}

	case REDUCTION:
	{
		m_view.zoom(-ViewControl::zoomValue);
		break;
	}

	}
}

void ViewControl::Move(short value)
{
	switch (value)
	{
		case TOP:
		{
			m_view.move(sf::Vector2f(0, -ViewControl::moveValue));
			break;
		}

		case RIGHT:
		{
			m_view.move(sf::Vector2f(ViewControl::moveValue, 0));
			break;
		}

		case DOWN:
		{
			m_view.move(sf::Vector2f(0, ViewControl::moveValue));
			break;
		}

		case LEFT:
		{
			m_view.move(sf::Vector2f(-ViewControl::moveValue, 0));
			break;
		}
	}

	m_window->ViewUpdate(&m_view);
}

void ViewControl::CheckKeyboard() //wyciagnac przed nawias viewUpdate(&m_view)
{
	if (sf::Keyboard::isKeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			ViewControl::Move(ViewControl::TOP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			ViewControl::Move(ViewControl::RIGHT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			ViewControl::Move(ViewControl::DOWN);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			ViewControl::Move(ViewControl::LEFT);
		}

		m_window->ViewUpdate(&m_view);
	}
	
}
