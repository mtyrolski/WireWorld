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
	ViewControl::Init(&window,sf::Vector2f(Loader::dimensions.x*Loader::ammount.x, Loader::dimensions.y*Loader::ammount.y));
	Cell::Init(Loader::dimensions,Loader::ammount, window.GetPointerToWindow());

	while (window.IsOpen())
	{
		sf::Event event;

		cEvent.checkEvent(&event);
		ViewControl::CheckKeyboard();

		window.Refresh();
		
	}

	return 0;
}