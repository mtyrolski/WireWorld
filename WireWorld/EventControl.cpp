#include "EventControl.h"

EventControl::EventControl(Window * winPointer)
{
	m_window = winPointer;
}


void EventControl::checkEvent(sf::Event *event)
{
	while ((m_window->GetPointerToWindow())->pollEvent(*event))
	{
		if (event->type == sf::Event::Closed ||
			event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape)
		{
			m_window->Close();
		}
	}
}
