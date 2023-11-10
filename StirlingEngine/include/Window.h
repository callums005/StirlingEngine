#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <utility>

namespace StirlingEngine
{
	class Window
	{
	public:
		Window(unsigned int width, unsigned int height, std::string title);

		~Window();

		bool IsOpen();
		bool PollEvent(sf::Event &event);
		void Render();
		void Close();

		std::pair<unsigned int, unsigned int> GetSize();
		std::string GetTitle();

	private:
		sf::RenderWindow *m_Window;

		unsigned int m_Width, m_Height;
		std::string m_Title;
	};
}