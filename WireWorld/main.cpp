#include <SFML/Graphics.hpp>
#include "Window.h"
#include "EventControl.h"
#include "ViewControl.h"
#include "MouseControl.h"
#include "Loader.h"
#include "GameControl.h"

int main()
{
	Loader::LoadData();

	Window window(Loader::title);
	EventControl cEvent(&window);
	ViewControl::Init(&window,sf::Vector2f(Loader::dimensions.x*Loader::ammount.x, Loader::dimensions.y*Loader::ammount.y),Loader::moveSpeed);
	Cell::Init(Loader::dimensions,Loader::ammount, window.GetPointerToWindow());
	MouseControl::Init(Loader::dimensions,Loader::ammount);

	while (window.IsOpen())
	{
		sf::Event event;
		cEvent.checkEvent(&event);

		if(GameControl::IsRun()) GameControl::Control();
		else MouseControl::Control(window.GetPointerToWindow());

		ViewControl::CheckKeyboard();
		

		window.Refresh();	
	}

	return 0;
}