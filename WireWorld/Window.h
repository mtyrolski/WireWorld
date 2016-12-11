#ifndef Window_h
#define Window_h

#include <SFML/Graphics.hpp>

class Window sealed
{
	sf::RenderWindow *m_window;

	std::vector<Cell> *m_cells;

	sf::View m_view;


	void display();
	void clear();

public:
	Window(sf::Vector2f dimentions,std::string title);
	void Refresh();
	bool IsOpen();
	sf::RenderWindow *GetPointerToWindow();
	void Close();
};

#endif // !Window_h
