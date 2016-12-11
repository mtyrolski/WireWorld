#include <SFML/Graphics.hpp>
#include "Window.h"
#include "EventControl.h"

int main()
{
	Window window(sf::Vector2f(25,25),"test");
	EventControl cEvent(&window);

	while (window.IsOpen())
	{
		sf::Event event;

		window.Refresh();
		cEvent.checkEvent(&event);
	}

	return 0;
}