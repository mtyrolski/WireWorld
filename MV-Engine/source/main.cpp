#pragma once

#include "MV/initializator/Initializator.hpp"

int main()
{
	mv::Initializator::createInstance();
	mv::Initializator::getInstance().init();
	
	//main game loop
	while (mv::Scene::getInstance().isOpen())
	{
		sf::Event event;

		mv::Scene::getInstance().clear();		
		mv::Ticker::tickLoop();

		mv::Scene::getInstance().drawCollection<mv::Cell>(mv::MapManager::getInstance().getCellStorage());
		mv::Scene::getInstance().drawCollection<mv::Statement>(&mv::StatementSystem::getInstance().getStatements());
		mv::Scene::getInstance().GetPointerToWindow()->draw(mv::Mouse::getInstance());
		
		mv::Scene::getInstance().display();

		mv::EventControl::getInstance().checkEvent(event);
	}


	return 0;
}
	
