#include "Loader.h"

const std::string Loader::path = "source/data/options.txt";

void Loader::LoadData()
{
	std::fstream file(path,std::ios::in);

	if (file.good())
	{
		file >> Loader::title;
		file >> Loader::dimensions.x;
		file >> Loader::dimensions.y;
	}
}
