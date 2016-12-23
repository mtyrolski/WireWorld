#include "Window.hpp"

void Window::display()
{
	m_window->display();
}

void Window::clear()
{
	m_window->clear(sf::Color::Black);
}

Window::Window(std::string title)
{
	m_window = new sf::RenderWindow(sf::VideoMode(Window::WIDTH, Window::HEIGHT), title);
	m_window->setFramerateLimit(128);
}

Window::~Window()
{
	delete m_window;
}

void Window::Refresh()
{
	clear();
	for (auto &var : Cell::cells) var.Draw();
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
