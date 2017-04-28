#include "Mouse.hpp"
#include <iostream>
namespace mv
{
	Mouse *Mouse::instance;

	void Mouse::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

	void Mouse::positionUpdate()
	{
		sf::Vector2i pixelPos = sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow());
		sf::Vector2f worldPos = mv::Scene::getInstance().GetPointerToWindow()->mapPixelToCoords(pixelPos);
		object.setPosition(worldPos);
	}

	void Mouse::checkBorders()
	{
		auto windowDimensions = mv::Scene::getInstance().GetPointerToWindow()->getSize();
		
		if (windowDimensions.y - sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).y < tolerance.y)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::DOWN);
		}
		else if (sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).y < tolerance.y)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::TOP);
		}

		if (windowDimensions.x - sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).x < tolerance.x)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::RIGHT);
		}
			
		else if (sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).x < tolerance.x)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::LEFT);
		}

	}

	void Mouse::checkClick()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			auto pos = Math::convertToUnitPosition(object.getPosition());

			if(MapManager::getInstance().isInMap(pos))
				(*MapManager::getInstance().getCellStorage())[pos.y*MapManager::getInstance().getUnitWorldSize().x + pos.x].changeState();
		}
	}

	Mouse::Mouse(const Mouse::TYPE & type, bool movingBorderPermission)
		:tolerance(mv::constants::defaults::BORDER_TOLERANCE.x, mv::constants::defaults::BORDER_TOLERANCE.y),
		Ticker(this), movingPermission(movingBorderPermission)
	{
		object.setTexture(*cache.get("data/textures/mouseAtlas.png"));
		object.setTextureRect(sf::IntRect(static_cast<int>(type)*constants::defaults::MOUSE_DIMENSIONS.x, 0, constants::defaults::MOUSE_DIMENSIONS.x, constants::defaults::MOUSE_DIMENSIONS.y));
		object.setOrigin(object.getGlobalBounds().width / 2, object.getGlobalBounds().height / 2);
	}

	Mouse & Mouse::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);

		return *instance;
	}

	void Mouse::createInstance(const Mouse::TYPE & type, bool movingBorderPermission)
	{
		if (instance == 0)
		{
			instance = new Mouse(type, movingBorderPermission);
		}
		else
		{
			Logger::Log(constants::error::singleton::SINGLETON_INITED, Logger::STREAM::CONSOLE, Logger::TYPE::INFO);
		}
	}

	Mouse::~Mouse()
	{
		Ticker::removePointer(this);
	}

	void Mouse::changeType(const Mouse::TYPE & type)
	{
		object.setTextureRect(sf::IntRect(static_cast<int>(type)*constants::defaults::MOUSE_DIMENSIONS.x, 0, constants::defaults::MOUSE_DIMENSIONS.x, constants::defaults::MOUSE_DIMENSIONS.y));
	}

	void Mouse::setBorderMovingMode(bool mode)
	{
		movingPermission = mode;
	}

	void Mouse::setTolerance(sf::Vector2u value)
	{
		tolerance = value;
	}

	void Mouse::setTolerance(unsigned long value_x, unsigned long value_y)
	{
		setTolerance(sf::Vector2u(value_x, value_y));
	}

	void Mouse::changeScale(float change)
	{
		object.setScale(sf::Vector2f(object.getScale().x+change, object.getScale().y+change));
	}

	void Mouse::tick()
	{
		positionUpdate();
		
		checkClick();

		if(movingPermission)
			checkBorders();
	}
}
