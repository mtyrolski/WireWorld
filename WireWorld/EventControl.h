#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "ViewControl.h"
#include "GameControl.h"

class EventControl
{
	Window *m_window;
public:
	EventControl(Window *winPointer);
	void checkEvent(sf::Event *event);
};
