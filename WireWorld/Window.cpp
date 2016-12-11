#include "Window.h"

void Window::display()
{
	m_window->display();
}

void Window::clear()
{
	m_window->clear(sf::Color(255, 255, 255));
}

Window::Window(sf::Vector2f dimentions, std::string title)
{
	m_window = new sf::RenderWindow(sf::VideoMode(dimentions.x, dimentions.y), title);
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
