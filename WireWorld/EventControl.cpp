#include "EventControl.h"

EventControl::EventControl(Window * winPointer)
{
	m_window = winPointer;
}


void EventControl::checkEvent(sf::Event *event)
{
	while ((m_window->GetPointerToWindow())->pollEvent(*event))
	{
		switch (event->type)
		{
			case sf::Event::Closed:
			{
				if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape)
				{
					m_window->Close();
				}
				break;
			}
			
			case sf::Event::MouseWheelMoved:
			{
				if (event->mouseWheel.delta > 0)
				{
					ViewControl::Zoom(ViewControl::ZOOM);
				}
				else
				{
					ViewControl::Zoom(ViewControl::REDUCTION);
				}
				break;
			}
		}
	}
}
