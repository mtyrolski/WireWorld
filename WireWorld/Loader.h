#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

class Loader sealed
{

	static const std::string path;

public:

	static std::string title;
	static sf::Vector2f dimensions;
	static sf::Vector2i ammount;

	static void LoadData();
};