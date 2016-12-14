#pragma once
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

class MouseControl sealed
{
	static const float interval;
	static float time_0_click;
	static sf::Vector2f dimensions;
public:
	static void Control(sf::RenderWindow *window);
	static void Init(sf::Vector2f dim);
};
