#include <SFML/Graphics.hpp>
#include "Window.h"
#include "EventControl.h"
#include "ViewControl.h"
#include "Loader.h"

int main()
{
	Loader::LoadData();

	Window window(Loader::dimensions,Loader::title);
	EventControl cEvent(&window);
	ViewControl::Init();

	while (window.IsOpen())
	{
		sf::Event event;

		cEvent.checkEvent(&event);
		ViewControl::CheckKeyboard();

		window.Refresh();
		
	}

	return 0;
}