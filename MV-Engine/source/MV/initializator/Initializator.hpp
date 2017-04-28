#pragma once

#include "MV/stateSystem/StateSystem.hpp"
#include "MV/config/Config.hpp"
#include "MV/resourceCache/Cache.hpp"
#include "MV/mapManager/MapManager.hpp"
#include "EventControl.hpp"
#include "MV/cell/Cell.hpp"
#include "MV/initializator/Initializator.hpp"
#include "MV/statementSystem/StatementSystem.hpp"
#include "MV/scene/Scene.hpp"
#include "MV/loader/Loader.hpp"
#include "MV/InputManager/InputManager.hpp"
#include "MV/mouse/Mouse.hpp"
#include "MV/ticker/Ticker.hpp"


namespace mv
{
	class Initializator
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		static Initializator *instance;
		/* ===Methods=== */
	public:
		//Inits the program
		void init();

		static Initializator& getInstance();
		static void createInstance();
	protected:
	private:
		Initializator() = default;
		Initializator(Initializator const& copy) = delete;            // Not Implemented
		Initializator& operator=(Initializator const& copy) = delete; // Not Implemented
	};
}
