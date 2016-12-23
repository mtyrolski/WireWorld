#include "ViewControl.h"

float ViewControl::moveValue;
const float ViewControl::zoomValue = 0.9f;
const float ViewControl::reductionValue = 1.1f;

sf::View ViewControl::m_view;
Window *ViewControl::m_window;


void ViewControl::Init(Window* window, sf::Vector2f windowDimensions, float moveSpeed)
{
	ViewControl::m_view.setSize(windowDimensions);
	m_window = window;
	m_view.setCenter(windowDimensions.x/2, windowDimensions.y/2);
	ViewControl::moveValue = moveSpeed;
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
		m_view.zoom(ViewControl::reductionValue);
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

		case DOWN:
		{
			m_view.move(sf::Vector2f(0, ViewControl::moveValue));
			break;
		}

		case RIGHT:
		{
			m_view.move(sf::Vector2f(ViewControl::moveValue, 0));
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			ViewControl::Move(ViewControl::RIGHT);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			ViewControl::Move(ViewControl::DOWN);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			ViewControl::Move(ViewControl::LEFT);
		}

		m_window->ViewUpdate(&m_view);
	}
	
}
