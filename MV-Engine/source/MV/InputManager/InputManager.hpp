#pragma once

#include <map>
#include <functional>

#include "SFML/Window/Keyboard.hpp"
#include "MV//ticker/Ticker.hpp"


namespace mv
{
	class InputManager : public Ticker
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		std::map < sf::Keyboard::Key, std::function<void()> > keyData;
		/* ===Methods=== */
	public:
		InputManager();
		~InputManager();

		void tick() override;

		bool addKeyToCheck(sf::Keyboard::Key key, std::function<void()> function);

		bool eraseKey(sf::Keyboard::Key key);
	protected:
	private:
	};
}

/*=================
Example of use:
void a()
{
std::cout << "a";
}

inputManager.addKeyToCheck(sf::Keyboard::A, a);

while(true)
	inputManager.control();
*/