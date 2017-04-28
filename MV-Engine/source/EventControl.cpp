#include "EventControl.hpp"

namespace mv
{
	EventControl* EventControl::instance;

	EventControl::EventControl(Scene * scene)
		:m_scene(scene)
	{	
	}

	void EventControl::checkEvent(sf::Event & event)
	{
		while(m_scene->GetPointerToWindow()->pollEvent(event))
		{
			switch (event.type)
			{	
				case sf::Event::Closed:
				{
					m_scene->close();
					break;
				}
				
				case sf::Event::MouseWheelMoved:
				{
					if (event.mouseWheel.delta < 0)
						Scene::getInstance().zoom(Scene::ZOOM_STATE::ZOOM);
					else 
						Scene::getInstance().zoom(Scene::ZOOM_STATE::DECREASE);

					break;
				}
				/*there you can add new case*/
			}
		}
	}

	EventControl & EventControl::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		return *instance;
	}

	void EventControl::createInstance(Scene *scene)
	{
		if (instance == 0)
			instance = new EventControl(scene);
	}
}

