#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Cell.hpp"

class Window sealed
{
	sf::RenderWindow *m_window;

	void display();
	void clear();

public:
	Window(std::string title);
	~Window();
	void Refresh();
	bool IsOpen();
	sf::RenderWindow *GetPointerToWindow();
	void Close();
	void ViewUpdate(sf::View *view);

	static enum
	{
		WIDTH = 600,
		HEIGHT = 600
	};
};
