#include "MouseControl.hpp"

const float MouseControl::interval = 0.2f;
float MouseControl::time_0_click;
sf::Vector2f MouseControl::dimensions;
sf::Vector2i MouseControl::ammount;


void MouseControl::Control(sf::RenderWindow *window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (clock() - time_0_click) / CLOCKS_PER_SEC > interval)
	{
		sf::Vector2i tempMousePos = sf::Mouse::getPosition(*window);
		sf::Vector2f mouseposition = window->mapPixelToCoords(tempMousePos);

		size_t i = mouseposition.x / dimensions.x;
		size_t j = mouseposition.y / dimensions.y;
		
		if(i+ ammount.x*j < ammount.x*ammount.y) Cell::cells[i + ammount.x*j].ChangeState();

		time_0_click = clock();
	}

}

void MouseControl::Init(sf::Vector2f dim, sf::Vector2i amm)
{
	time_0_click = clock();
	dimensions = dim;
	ammount = amm;
}
