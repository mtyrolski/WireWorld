#include "simulator.hpp"

Simulator* Simulator::instance;


Simulator::state_t Simulator::getState()
{
	return state;
}

void Simulator::setState( state_t type )
{
	state = type;
}

Simulator& Simulator::getInstance()
{
	if ( instance == nullptr )
		mv::Logger::Log( mv::constants::error::singleton::SINGLETON_NOT_INITED, mv::Logger::STREAM::BOTH, mv::Logger::TYPE::ERROR );
	return *instance;
}

void Simulator::createInstance()
{
	if ( instance == nullptr )
		instance = new Simulator();
}

void Simulator::tick()
{
	if( state==state_t::SIMULATION )
	{
		//modifyCells();
	}
}

void Simulator::runSimulation()
{
	state = state_t::SIMULATION;
}

void Simulator::stopSimulation()
{
	state = state_t::EDITING;
}

Simulator::Simulator()
	:Ticker(this),state(state_t::EDITING)
{
	inputManager.addKeyToCheck( sf::Keyboard::R, []() { Simulator::getInstance().runSimulation(); } );
	inputManager.addKeyToCheck( sf::Keyboard::B, []() { Simulator::getInstance().stopSimulation(); } );
	inputManager.addKeyToCheck( sf::Keyboard::C, []() { mv::MapManager::getInstance().resetAllCells(); } );
}
