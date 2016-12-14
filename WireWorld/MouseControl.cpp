#include "MouseControl.h"

const float MouseControl::interval = 0.2f;
float MouseControl::time_0_click;
sf::Vector2f MouseControl::dimensions;


void MouseControl::Control(sf::RenderWindow *window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (clock() - time_0_click) / CLOCKS_PER_SEC > interval)
	{
		sf::Vector2i tempMousePos = sf::Mouse::getPosition(*window);
		sf::Vector2f mouseposition = window->mapPixelToCoords(tempMousePos);

		size_t i = mouseposition.x / dimensions.x;
		size_t j = mouseposition.y / dimensions.y;
		
		if(i+ dimensions.x*j<dimensions.x*dimensions.y) Cell::cells[i + dimensions.x*j].ChangeState();

		time_0_click = clock();
	}

}

void MouseControl::Init(sf::Vector2f dim)
{
	time_0_click = clock();
	dimensions = dim;
}
