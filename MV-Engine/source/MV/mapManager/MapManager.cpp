#include "MapManager.hpp"

namespace mv
{
	MapManager* MapManager::instance;

	void MapManager::createWorld(uint8_t defaultStateNumber)
	{
		for (int j = 0; j < unitWorldSize.y; j++)
		{
			for (int i = 0; i < unitWorldSize.x; i++)
			{
				map.emplace_back(sf::Vector2i{i,j}, cellDimensions, defaultStateNumber);
			}
		}
	}


	MapManager::MapManager(sf::Vector2i uWorldSize, const sf::Vector2f & cellDim)
		:Ticker(this)
	{
		if (uWorldSize.x <= 0 || cellDim.x <= 0 ||
			uWorldSize.y <= 0 || cellDim.y <= 0)
		{
			Logger::Log(constants::error::mapManager::NEGATIVE_VALUES, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			return;
		}
		MapManager::unitWorldSize = uWorldSize;
		MapManager::cellDimensions = cellDim;
	}


	MapManager & MapManager::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		return *instance;
	}

	void MapManager::createInstance(sf::Vector2i uWorldSize, const sf::Vector2f & cellDim)
	{
		if (instance == 0)
			instance = new MapManager(uWorldSize,cellDim);
		else
		{
			Logger::Log(constants::error::singleton::SINGLETON_INITED, Logger::STREAM::CONSOLE, Logger::TYPE::INFO);
		}
	}

	sf::Vector2i MapManager::getUnitWorldSize()
	{
		return MapManager::unitWorldSize;
	}
	sf::Vector2f MapManager::getCellDimensions()
	{
		return MapManager::cellDimensions;
	}

	std::vector<Cell>* MapManager::getCellStorage()
	{
		return &map;
	}

	bool MapManager::constructWholeWorld(const std::string& defaultState)
	{
		initialState = StateSystem::getNumberOfState(defaultState);

		if (!StateSystem::isStateExist(initialState))
		{
			Logger::Log(constants::error::stateSystem::NUMBER_HAS_NOT_FOUND, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			return false;
		}

		MapManager::createWorld(initialState);

	}

	void MapManager::updateCells()
	{
		for (auto&var : map)
			var.update();
		
	}

	void MapManager::setDefaultState(Cell& cell)
	{
		cell.setState(initialState);
	}

	void MapManager::resetAllCells()
	{
		for (auto&var : map)
			var.setState(initialState);
	}

	void MapManager::setOutlineColor(const sf::Color & color)
	{
		for (auto&var : map)
			var.setOutlineColor(color);
	}

	bool MapManager::isInMap(sf::Vector2i & unitPosition)
	{
		return isInMap(unitPosition.x, unitPosition.y);
	}

	bool MapManager::isInMap(unsigned int i, unsigned int j)
	{
		return i >= 0 && i < unitWorldSize.x &&
			j >= 0 && j < unitWorldSize.y;
	}

	void MapManager::tick()
	{
		updateCells();
	}
}

