#include "FPScontroller.hpp"

const sf::Time FPScontroller::timeStep = sf::seconds(1.f / 60.f);
sf::Time FPScontroller::timeFromUptade = sf::Time::Zero;
sf::Clock FPScontroller::timer;

bool FPScontroller::TimeStepHasNotExpired()
{
	return timeFromUptade > timeStep;
}

void FPScontroller::ReduceUpdateTime()
{
	timeFromUptade -= timeStep;
}
