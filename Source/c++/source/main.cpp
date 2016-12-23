#include "Window.hpp"
#include "EventControl.hpp"
#include "ViewControl.hpp"
#include "MouseControl.hpp"
#include "Loader.hpp"
#include "FPScontroller.hpp"
#include "GameControl.hpp"
#include "Cell.hpp"

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
		sf::Time time = FPScontroller::timer.restart();
		FPScontroller::timeFromUptade += time;
		
		while (FPScontroller::TimeStepHasNotExpired())
		{
			FPScontroller::ReduceUpdateTime();

			sf::Event event;
			cEvent.checkEvent(&event);

			if (GameControl::IsRun()) GameControl::Control();
			else MouseControl::Control(window.GetPointerToWindow());

			ViewControl::CheckKeyboard();


			window.Refresh();
		}	
	}

	return 0;
}