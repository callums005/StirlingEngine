#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <utility>

namespace StirlingEngine
{
	class Window
	{
	private:
		sf::RenderWindow *m_Window;

		uint m_Width, m_Height;
		std::string m_Title;

	public:
		Window(uint width, uint height, std::string title);

		~Window();

		bool IsOpen();
		bool PollEvent(sf::Event &event);
		void Render();
		void Close();

		std::pair<uint, uint> GetSize();
		std::string GetTitle();
	};
}