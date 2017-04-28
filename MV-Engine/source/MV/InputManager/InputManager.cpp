#include "InputManager.hpp"

namespace mv
{
	InputManager::InputManager()
		:Ticker(this)
	{
	}

	InputManager::~InputManager()
	{
		Ticker::removePointer(this);
	}

	void InputManager::tick()
	{
		for (auto&var : keyData)
			if (sf::Keyboard::isKeyPressed(var.first))
				var.second();
	}

	bool InputManager::addKeyToCheck(sf::Keyboard::Key key, std::function<void()> function)
	{
		keyData.emplace(key, function);

		return true;
	}



	bool InputManager::eraseKey(sf::Keyboard::Key key)
	{
		keyData.erase(key);
		return false;
	}
}
