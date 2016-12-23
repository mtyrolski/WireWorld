#include "Loader.hpp"

const std::string Loader::path = "source/Loader/data/options.txt";
float Loader::moveSpeed;

 std::string Loader::title;
 sf::Vector2f Loader::dimensions;
 sf::Vector2i Loader::ammount;

void Loader::LoadData()
{
	std::fstream file(path,std::ios::in);

	if (file.good())
	{
		file >> Loader::title;
		file >> Loader::dimensions.x;
		file >> Loader::dimensions.y;
		file >> Loader::ammount.x;
		file >> Loader::ammount.y;
		file >> Loader::moveSpeed;
	}
}
