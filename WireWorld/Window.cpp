#include "Window.h"

void Window::display()
{
	m_window->display();
}

void Window::clear()
{
	m_window->clear(sf::Color(255, 255, 255));
}

Window::Window(sf::Vector2f dimensions, std::string title)
{
	m_window = new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), title);
}

Window::~Window()
{
	delete m_window;
}

void Window::Refresh()
{
	clear();
	for (auto& var : *m_cells) var.Draw();
	display();
}

bool Window::IsOpen()
{
	return m_window->isOpen();
}

sf::RenderWindow * Window::GetPointerToWindow()
{
	return m_window;
}

void Window::Close()
{
	m_window->close();
}

void Window::ViewUpdate(sf::View *view)
{
	m_window->setView(*view);
}
