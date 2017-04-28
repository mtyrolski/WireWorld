#include "Loader.hpp"

namespace mv
{
	Loader* Loader::instance = nullptr;

	void Loader::loadData()
	{
		std::ifstream file("data/options/options.txt");

		if (file.good())
		{
			file >> Loader::title;
			file >> Loader::cellDimensions.x;
			file >> Loader::cellDimensions.y;
			file >> Loader::ammount.x;
			file >> Loader::ammount.y;
			file >> Loader::moveSpeed;
		}
	}


	Loader& Loader::getInstance()
	{
		if (instance == nullptr)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		
		return *instance;
	}

	void Loader::createInstance()
	{
		if (instance == 0)
			instance = new Loader;
		else
		{
			Logger::Log(constants::error::singleton::SINGLETON_INITED, Logger::STREAM::CONSOLE, Logger::TYPE::INFO);
		}
	}
}
