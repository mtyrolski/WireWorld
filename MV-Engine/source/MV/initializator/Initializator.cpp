#include "Initializator.hpp"


namespace mv
{
	Initializator* Initializator::instance;

	void Initializator::init()
	{
		StateSystem::readStatesFromFile("data/states/states.txt");

		mv::Loader::createInstance();
		mv::Loader::getInstance().loadData();

		mv::MapManager::createInstance(mv::Loader::getInstance().ammount, mv::Loader::getInstance().cellDimensions);
		mv::MapManager::getInstance().constructWholeWorld(mv::constants::defaults::EMPTY);

		mv::Scene::createInstance(mv::Loader::getInstance().title, sf::Vector2f(mv::Loader::getInstance().ammount.x*mv::Loader::getInstance().cellDimensions.x, mv::Loader::getInstance().ammount.y*mv::Loader::getInstance().cellDimensions.y));

		mv::EventControl::createInstance(&mv::Scene::getInstance());

		mv::StatementSystem::createInstance();

		mv::Mouse::createInstance();
	}

	Initializator & Initializator::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		
		return *instance;
	}

	void Initializator::createInstance()
	{
		if (instance == nullptr)
			instance = new Initializator();
	}
}


