#include "Scene.hpp"

namespace mv
{
	Scene* Scene::instance;

	void Scene::display()
	{
		window->display();
	}

	Scene & Scene::getInstance()
	{
		if (instance == nullptr)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
	
		return *instance;
	}

	void Scene::createInstance(const std::string& title, const sf::Vector2f& dimensions, float speed)
	{
		if (instance == 0)
		{
			instance = new Scene(title, dimensions);
			instance->view.setCenter((MapManager::getInstance().getCellDimensions().x*MapManager::getInstance().getUnitWorldSize().x)/2.f,(MapManager::getInstance().getCellDimensions().y*MapManager::getInstance().getUnitWorldSize().y)/2.f);
			instance->window->setView(instance->view);
			instance->window->setFramerateLimit(128);
			instance->viewSpeed = speed;
			instance->window->setMouseCursorVisible(false);
		}
		else
		{
			Logger::Log(constants::error::singleton::SINGLETON_INITED, Logger::STREAM::CONSOLE, Logger::TYPE::INFO);
		}
	}


	void Scene::clear()
	{
		window->clear();
	}

	Scene::Scene(const std::string& title, const sf::Vector2f& dimensions)
		:viewSpeed(2.f)
	{
		window = new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), title);
		
		inputManager.addKeyToCheck(sf::Keyboard::A, []() { mv::Scene::getInstance().moveViewLeft(); });
		inputManager.addKeyToCheck(sf::Keyboard::D, []() { mv::Scene::getInstance().moveViewRight(); });
		inputManager.addKeyToCheck(sf::Keyboard::W, []() { mv::Scene::getInstance().moveViewTop(); });
		inputManager.addKeyToCheck(sf::Keyboard::S, []() { mv::Scene::getInstance().moveViewDown(); });
	}

	Scene::~Scene()
	{
		if (window != nullptr)
			delete window;
	}

	bool Scene::isOpen() const
	{
		return window->isOpen();
	}

	void Scene::zoom(ZOOM_STATE state)
	{
		switch (state)
		{
			case ZOOM_STATE::ZOOM:
			{
				instance->view.zoom(1+constants::scene::ZOOM_SPEED);
				break;
			}

			case ZOOM_STATE::DECREASE:
			{
				instance->view.zoom(1-constants::scene::ZOOM_SPEED);
				break;
			}
		}

		instance->window->setView(instance->view);
	}

	void Scene::moveView(DIRECTION direction)
	{
		switch (direction)
		{
			case DIRECTION::TOP:
			{
				view.move(0,-viewSpeed);
				break;
			}
			case DIRECTION::RIGHT:
			{
				view.move(viewSpeed,0);
				break;
			}
			case DIRECTION::DOWN:
			{
				view.move(0, viewSpeed);
				break;
			}
			case DIRECTION::LEFT:
			{
				view.move(-viewSpeed, 0);
				break;
			}
		}
		window->setView(view);
	}

	float Scene::getMoveSpeed()
	{
		return viewSpeed;
	}

	void Scene::setMoveSpeed(float value)
	{
		viewSpeed = value;
	}

	sf::RenderWindow * Scene::GetPointerToWindow()
	{
		return window;
	}

	void Scene::close()
	{
		window->close();
	}

	void Scene::moveViewRight()
	{
		moveView(DIRECTION::RIGHT);
	}

	void Scene::moveViewLeft()
	{
		moveView(DIRECTION::LEFT);
	}

	void Scene::moveViewTop()
	{
		moveView(DIRECTION::TOP);
	}

	void Scene::moveViewDown()
	{
		moveView(DIRECTION::DOWN);
	}

}
