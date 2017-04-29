#pragma once

#include <ctime>

#include "MV/InputManager/InputManager.hpp"
#include "MV/ticker/Ticker.hpp"
#include "MV/logger/Logger.hpp"
#include "MV/config/Config.hpp"
#include "MV/MapManager/MapManager.hpp"

class Simulator : public mv::Ticker
{
	/* ===Objects=== */
public:
	enum class state_t
	{
		SIMULATION,
		EDITING
	};
protected:
private:
	
	state_t state;
	mv::InputManager inputManager;
	static Simulator* instance;

	float frequency;

	float lastTimePoint;

	/* ===Methods=== */
public:

	state_t getState();

	void setState( state_t type );

	static Simulator& getInstance();
	static void createInstance();

	void controlCells();
	void tick() override;

	void runSimulation();
	void stopSimulation();

	void setFrequency(float value);

protected:
private:
	Simulator(); // Not Implemented
	Simulator( Simulator const& copy ) = delete;            // Not Implemented
	Simulator& operator=( Simulator const& copy ) = delete; // Not Implemented

};