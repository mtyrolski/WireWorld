#ifndef Window_h
#define Window_h

#include <SFML/Graphics.hpp>
#include "Cell.h"

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

#endif // !Window_h
