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
	Window(sf::Vector2f dimensions,std::string title);
	~Window();
	void Refresh();
	bool IsOpen();
	sf::RenderWindow *GetPointerToWindow();
	void Close();
	void ViewUpdate(sf::View *view);
};

#endif // !Window_h
