#include <SFML/Graphics.hpp>
#include "Window.h"
#include "EventControl.h"
#include "ViewControl.h"
#include "MouseControl.h"
#include "Loader.h"

int main()
{
	Loader::LoadData();

	Window window(sf::Vector2f(Loader::dimensions.x*Loader::ammount.x, Loader::dimensions.y*Loader::ammount.y),Loader::title);
	EventControl cEvent(&window);
	ViewControl::Init(&window,sf::Vector2f(Loader::dimensions.x*Loader::ammount.x, Loader::dimensions.y*Loader::ammount.y));
	Cell::Init(Loader::dimensions,Loader::ammount, window.GetPointerToWindow());
	MouseControl::Init(Loader::dimensions);

	while (window.IsOpen())
	{
		sf::Event event;

		cEvent.checkEvent(&event);
		ViewControl::CheckKeyboard();
		MouseControl::Control(window.GetPointerToWindow());

		window.Refresh();
		
	}

	return 0;
}