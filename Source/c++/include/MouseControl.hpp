#pragma once
#include "Cell.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <ctime>

class MouseControl sealed
{
	static const float interval;
	static float time_0_click;
	static sf::Vector2f dimensions;
	static sf::Vector2i ammount;
public:
	static void Control(sf::RenderWindow *window);
	static void Init(sf::Vector2f dim,sf::Vector2i amm);
};
