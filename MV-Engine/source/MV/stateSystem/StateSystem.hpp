#pragma once

#include <fstream>
#include <map>

#include <SFML/Graphics/Color.hpp>

#include "MV/config/Config.hpp"
#include "MV/logger/Logger.hpp"

namespace mv
{
	class StateSystem
	{
		/* ===Objects=== */
	public:
	protected:
		static std::map<std::string, std::pair<int8_t, sf::Color>> states;
	private:
		/* ===Methods=== */
	public:
		//Emplaces new state into state map
		//returns false if state with given name/number exist or number<0 or color is not correct
		//returns true if state has been added
		static bool emplaceState(const std::string& name, int8_t number, sf::Color& color);

		//Reads all states 
		//returns false if path is not correct
		//returns true if states have been readed correctly
		static bool readStatesFromFile(const std::string& path);

		//Returns false if state with given name doesn't exist
		//returns true if state with given name exist
		static bool isStateExist(const std::string& name);

		//Returns false if state with given number doesn't exist
		//returns true if state with given number exist
		static bool isStateExist(uint8_t number);

		//Returns number of state with given name
		//returns -1 value if state doesn't exist
		static int8_t getNumberOfState(const std::string& name);

		//Returns color of state
		//returns white if state with given name does not exist
		static sf::Color getColorOfState(std::string& name);

		//Returns color of state
		//returns white if state with given number does not exist
		static sf::Color getColorOfState(int8_t number);

		//Returns name of state
		//returns -1 if state with given number doesn't exist
		static std::string getNameOfState(int8_t number);

		//Erase state with given name
		//returns false if state doesn't exist
		//returns true if state has been removed
		static bool eraseState(std::string& name);

		//Returns ammount of states
		static int8_t getAmmountStates();
	protected:
	private:
	};
}
