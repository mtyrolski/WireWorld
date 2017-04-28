#include "Cell.hpp"

namespace mv
{
	void Cell::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(shape, states);
	}

	void Cell::setColor(sf::Color color)
	{
		shape.setFillColor(color);
	}

	void Cell::setBasicParameters(int stateNumber, sf::Vector2f & cellDimensions, sf::Vector2i & uPos)
	{
		if (!StateSystem::isStateExist(stateNumber))
		{
			Logger::Log(constants::error::stateSystem::STATE_DOES_NOT_EXIST, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			state = StateSystem::getNumberOfState(constants::defaults::EMPTY);
		}
		else
		{
			state = stateNumber;
			setColor(StateSystem::getColorOfState(state));
		}
	}

	void Cell::setBasicParameters(const std::string& name, sf::Vector2f & cellDimensions, sf::Vector2i & uPos)
	{
		if (!StateSystem::isStateExist(name))
		{
			Logger::Log(constants::error::stateSystem::STATE_DOES_NOT_EXIST, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			state = StateSystem::getNumberOfState(constants::defaults::EMPTY);
		}
		else
		{
			state = StateSystem::getNumberOfState(name);
			setColor(StateSystem::getColorOfState(state));
		}
	}

	void Cell::setVisualSettings(sf::Vector2f & cellDimensions, sf::Vector2i & uPos)
	{
		shape.setSize(cellDimensions);
		shape.setOutlineThickness(cellDimensions.x / 10.0f); //10%
		shape.setOutlineColor(constants::cell::FILL_COLOR);
		shape.setPosition(uPos.x*cellDimensions.x, uPos.y*cellDimensions.y);
	}



	Cell::Cell(sf::Vector2i& uPos, sf::Vector2f& cellDimensions, const std::string& stateName)
		:unitPosition(uPos), lastClickTime(clock()),nextState(0)
	{
		setVisualSettings(cellDimensions, uPos);
		setBasicParameters(stateName,cellDimensions,uPos);
	}

	Cell::Cell(sf::Vector2i & uPos, sf::Vector2f & cellDimensions, int stateNumber)
		:unitPosition(uPos),lastClickTime(clock()), nextState(0)
	{
		setVisualSettings(cellDimensions, uPos);
		setBasicParameters(stateNumber,cellDimensions,uPos);
	}

	void Cell::changeState(int shift)
	{
		nextState = state + shift;
		nextState %= StateSystem::getAmmountStates();
		setColor(StateSystem::getColorOfState(nextState));
	}

	void Cell::changeState()
	{
		if ((clock() - lastClickTime) / CLOCKS_PER_SEC > constants::mouse::FREQUENCY)
		{
			changeState(1);
			lastClickTime = clock();
		}	
	}

	uint8_t Cell::getState() const
	{
		return state;
	}

	bool Cell::setState(std::string stateName)
	{
		if (StateSystem::getNumberOfState(stateName) != constants::error::stateSystem::ERROR_VALUE)
		{
			state = StateSystem::getNumberOfState(stateName);
			setColor(StateSystem::getColorOfState(stateName));
			return true;
		}

		return false;
	}

	bool Cell::setState(uint8_t stateNumber)
	{
		if (StateSystem::isStateExist(stateNumber))
		{
			state = stateNumber;
			return true;
		}
		else Logger::Log(constants::error::stateSystem::NUMBER_HAS_NOT_FOUND,Logger::STREAM::BOTH,Logger::TYPE::ERROR);

		return false;
	}

	void Cell::update()
	{
		state = nextState;
	}

	void Cell::setOutlineColor(const sf::Color & color)
	{
		shape.setOutlineColor(color);
	}
}