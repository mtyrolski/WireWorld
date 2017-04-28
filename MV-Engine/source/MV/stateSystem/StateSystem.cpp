#include "StateSystem.hpp"

namespace mv
{
	std::map<std::string, std::pair<int8_t,sf::Color>> StateSystem::states;

	bool StateSystem::emplaceState(const std::string& name, int8_t number, sf::Color& color)
	{
		if (states.find(name) != states.end())
		{
			Logger::Log(constants::error::stateSystem::STATE_HAS_FOUND, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return false;
		}
		else if (number < 0)
		{
			Logger::Log(constants::error::stateSystem::MINUS_NUMBER, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return false;
		}

		states.emplace(name, std::pair<int8_t, sf::Color>{number, color});
		return true;
	}

	bool StateSystem::readStatesFromFile(const std::string& path)
	{
		std::ifstream file(path);

		if (!file.good())
		{
			Logger::Log(mv::constants::error::fileManager::PATH_IS_NOT_CORRET,mv::Logger::STREAM::BOTH,mv::Logger::TYPE::ERROR);
			return false;
		}

		int number;
		int colorComponents[3];
		std::string name;

		while (file >> name)
		{
			file >> number;

			for (int8_t i = 0; i < 3; i++)
				file >> colorComponents[i];
			
			StateSystem::emplaceState(name, number, sf::Color(colorComponents[0], colorComponents[1], colorComponents[2]));
		}

		return true;
	}

	bool StateSystem::isStateExist(const std::string& name)
	{
		return (states.find(name) != states.end());
	}

	bool StateSystem::isStateExist(uint8_t number)
	{
		for (auto&var : states)
		{
			if (var.second.first == number)
				return true;
		}

		return false;
	}

	int8_t StateSystem::getNumberOfState(const std::string& name)
	{
		auto itr = states.find(name);

		if (itr == states.end()) return constants::error::stateSystem::ERROR_VALUE;
		else return itr->second.first;
	}

	sf::Color StateSystem::getColorOfState(std::string& name)
	{
		if (StateSystem::isStateExist(name))
			return states[name].second;
		return sf::Color::White;
	}

	sf::Color StateSystem::getColorOfState(int8_t number)
	{
		auto itr = states.find(StateSystem::getNameOfState(number));
		
		if (itr == states.end())
			return sf::Color::White;

		return itr->second.second;
	}

	std::string StateSystem::getNameOfState(int8_t number)
	{
		for (auto&var : states)
			if (var.second.first == number)
				return var.first;


		Logger::Log(constants::error::stateSystem::NUMBER_HAS_NOT_FOUND, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		return constants::error::stateSystem::ERROR_NAME;
	}

	bool StateSystem::eraseState(std::string& name)
	{
		auto itr = states.find(name);
		
		if (itr == states.end()) return false;

		states.erase(itr);
		return true;
	}

	int8_t StateSystem::getAmmountStates()
	{
		return states.size();
	}
}
