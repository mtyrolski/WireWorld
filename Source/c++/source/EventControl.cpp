#include "EventControl.hpp"

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
				m_window->Close();
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

			case sf::Event::KeyPressed:
			{
				if (event->key.code == sf::Keyboard::Escape)
				{
					m_window->Close();
				}
				else if (event->key.code == sf::Keyboard::R)//run the game
				{
					GameControl::Run();
				}
				else if (event->key.code == sf::Keyboard::B) //break the game
				{
					GameControl::Stop();
				}
				else if (event->key.code == sf::Keyboard::C) //set all cells as empty and stop the game
				{
					GameControl::Clear();
				}
				break;
			}
		}
	}
}
