#pragma once

#include <ctime>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "MV/config/Config.hpp"
#include "MV/stateSystem/StateSystem.hpp"

namespace mv
{
	class Cell : public sf::Drawable
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		//Shape of cell
		sf::RectangleShape shape;

		//State of cell
		uint8_t state;

		//State of cell in next cycle
		uint8_t nextState;

		//Position in unit system
		const sf::Vector2i unitPosition;

		float lastClickTime;

		/* ===Methods=== */
	public:

		Cell(sf::Vector2i& uPos, sf::Vector2f& cellDimensions, const std::string& stateName);
		Cell(sf::Vector2i& uPos, sf::Vector2f& cellDimensions, int stateNumber);

		//Change state for given shift
		void changeState(int shift);

		//Change state for 1 
		void changeState();

		//Returns number of state
		uint8_t getState() const;

		//Change cell's state to given name
		//returns false if state hasn't been changed
		//returns true if state has been changed
		bool setState(std::string stateName);

		//Change cell's state to given number
		//returns false if state hasn't been changed
		//returns true if state has been changed
		bool setState(uint8_t stateNumber);

		//Updates cell state to next state
		void update();

		//Sets outline color of cell
		void setOutlineColor(const sf::Color& color);

	protected:
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void setColor(sf::Color color);


		void setBasicParameters(int stateNumber, sf::Vector2f& cellDimensions, sf::Vector2i& uPos);
		void setBasicParameters(const std::string& name, sf::Vector2f& cellDimensions, sf::Vector2i& uPos);

		void setVisualSettings(sf::Vector2f& cellDimensions, sf::Vector2i& uPos);
	};
}
