#pragma once
#include "Window.hpp"
#include "ViewControl.hpp"
#include "GameControl.hpp"
#include <SFML/Window/Event.hpp>

class EventControl
{
	Window *m_window;
public:
	EventControl(Window *winPointer);
	void checkEvent(sf::Event *event);
};
