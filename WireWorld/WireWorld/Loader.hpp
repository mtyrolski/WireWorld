#pragma once

#include <iostream>
#include <fstream>
#include <SFML/System/Vector2.hpp>
#include <string>

class Loader sealed
{
	static const std::string path;

public:

	static std::string title;
	static sf::Vector2f dimensions;
	static sf::Vector2i ammount;
	static float moveSpeed;

	static void LoadData();
};