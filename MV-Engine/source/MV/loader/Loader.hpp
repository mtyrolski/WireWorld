#pragma once

#include <fstream>
#include <string>

#include <SFML/System/Vector2.hpp>

#include "MV/config/Config.hpp"
#include "MV/logger/Logger.hpp"

namespace mv
{
	class Loader final
	{
		/* ===Objects=== */
	public:
		//title of the window
		std::string title;

		//dimensions of single cell
		sf::Vector2f cellDimensions;

		//ammount of cells on the map
		sf::Vector2i ammount;

		//speed of camera(view)
		float moveSpeed;
	protected:
	private:
		static Loader* instance;


		/* ===Methods=== */
	public:
		static Loader& getInstance();
		static void createInstance();

		//Loads data from file
		//title
		//dimensions
		//amount
		//speed of camera(view)
		void loadData();
	protected:
	private:
		Loader() = default;
		Loader(Loader const& copy) = delete;            // Not Implemented
		Loader& operator=(Loader const& copy) = delete; // Not Implemented
	};
}
