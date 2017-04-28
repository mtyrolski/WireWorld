#pragma once

#include <SFML/Window/Event.hpp>

#include "MV/scene/Scene.hpp"

/*
				===---===
	If you want to extend event control you need to modife checkControl() method:
	-Add new case like this:

	case sf::Event::MouseLeft:
	{
		do sth...
		break;
	}
			    ===---===
*/

namespace mv
{
	class EventControl
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		Scene* m_scene;
		static EventControl *instance;
		/* ===Methods=== */
	public:
		void checkEvent(sf::Event &event);
		static EventControl& getInstance();
		static void createInstance(Scene *scene);
	protected:
	private:
		EventControl(Scene *scene);
		EventControl() = delete; // Not Implemented
		EventControl(EventControl const& copy) = delete;            // Not Implemented
		EventControl& operator=(EventControl const& copy) = delete; // Not Implemented
	};
}
