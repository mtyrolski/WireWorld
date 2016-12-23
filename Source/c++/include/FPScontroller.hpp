#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
class FPScontroller
{ 
public:	
	static const sf::Time timeStep;
	static sf::Clock timer;
	static sf::Time timeFromUptade;

	static bool TimeStepHasNotExpired();
	static void ReduceUpdateTime();
};