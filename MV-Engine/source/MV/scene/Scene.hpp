#pragma once

#include <type_traits>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "MV/config/Config.hpp"
#include "MV/cell/Cell.hpp"
#include "MV/mapManager/MapManager.hpp"
#include "MV/InputManager/InputManager.hpp"
#include "MV/mouse/Mouse.hpp"


namespace mv
{
	class Scene
	{
		/* ===Objects=== */
	public:

		enum class ZOOM_STATE
		{
			ZOOM,
			DECREASE
		};

		enum class DIRECTION
		{
			TOP,
			RIGHT,
			DOWN,
			LEFT
		};

	protected:
	private:
		sf::RenderWindow *window;
		sf::View view;

		static Scene* instance;

		mv::InputManager inputManager;

		friend class InputManager;
		friend class Initializator;

		float viewSpeed;
		/* ===Methods=== */
	public:
		static Scene& getInstance();

		static void createInstance(const std::string& title = constants::defaults::UNNAMED, const sf::Vector2f& dimensions = constants::defaults::WINDOW_DIMENSIONS, float speed = 1.f);

		~Scene();

		//Display on screen what has been rendered to the window so far
		void display();

		//Clears window
		void clear();

		//Tell whether or not the window is open
		bool isOpen() const;

		void zoom(ZOOM_STATE state);

		void moveView(DIRECTION direction);

		//Draws given collection of T objects
		//returns false if T doesn't inhert from sf::Drawable
		template < typename T = typename std::enable_if< std::is_base_of<sf::Drawable, T>::value, T>::type>
		bool drawCollection(std::vector<T> *collection);

		float getMoveSpeed();

		void setMoveSpeed(float value);

		sf::RenderWindow *GetPointerToWindow();

		void close();

		void moveViewRight();
		void moveViewLeft();
		void moveViewTop();
		void moveViewDown();
	protected:
	private:
		Scene(const std::string& title = constants::defaults::UNNAMED, const sf::Vector2f& dimensions = constants::defaults::WINDOW_DIMENSIONS);
		Scene() = delete;  // Not Implemented
		Scene(Scene const& copy) = delete;            // Not Implemented
		Scene& operator=(Scene const& copy) = delete; // Not Implemented	
	};


	template<typename T>
	inline bool Scene::drawCollection(std::vector<T>* collection)
	{
		for (auto&var : *collection)
			window->draw(var);

		return true;
	}
}