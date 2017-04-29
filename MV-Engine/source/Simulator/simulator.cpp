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

void Simulator::controlCells()
{
	if ( (clock() - lastTimePoint) / CLOCKS_PER_SEC > frequency )
	{
		for ( auto &var : *mv::MapManager::getInstance().getCellStorage() )
			var.computeState();

		lastTimePoint = clock();
	}
}

void Simulator::tick()
{
	if( state==state_t::SIMULATION )
	{
		controlCells();
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

void Simulator::setFrequency(float value)
{
	frequency = value;
}

Simulator::Simulator()
	:Ticker(this),state(state_t::EDITING), lastTimePoint(clock()),frequency(mv::constants::simulator::FREQUENCY)
{
	inputManager.addKeyToCheck( sf::Keyboard::R, []() { Simulator::getInstance().runSimulation(); } );
	inputManager.addKeyToCheck( sf::Keyboard::B, []() { Simulator::getInstance().stopSimulation(); } );
	inputManager.addKeyToCheck( sf::Keyboard::C, []() { mv::MapManager::getInstance().resetAllCells(); } );
}
