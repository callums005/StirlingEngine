#include "Window.h"

namespace StirlingEngine
{
	Window::Window(unsigned int width, unsigned int height, std::string title)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		m_Window = new sf::RenderWindow(sf::VideoMode(m_Width, m_Height), m_Title);
		m_Window->setFramerateLimit(60);
	}

	Window::~Window()
	{
	}

	bool Window::IsOpen()
	{
		return m_Window->isOpen();
	}

	bool Window::PollEvent(sf::Event &event)
	{
		return m_Window->pollEvent(event);
	}

	void Window::Render()
	{
		m_Window->clear(sf::Color::Red);

		// Draw Stuff here

		m_Window->display();
	}

	void Window::Close()
	{
		m_Window->close();
	}

	std::pair<unsigned int, unsigned int> Window::GetSize()
	{
		return std::pair<unsigned int, unsigned int>(m_Width, m_Height);
	}

	std::string Window::GetTitle()
	{
		return m_Title;
	}
}