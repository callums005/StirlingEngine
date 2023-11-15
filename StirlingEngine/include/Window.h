#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <utility>

namespace StirlingEngine
{
	class Window
	{
	public:
		/// @brief Constructor to set window configurations
		/// @param width The width of the window
		/// @param height The height of the window
		/// @param title The title of the window
		Window(unsigned int width, unsigned int height, std::string title);

		/// @brief Deconstructor
		~Window();

		/// @brief Checks of the window is open
		/// @return If the window is open
		bool IsOpen();

		/// @brief Polls the events
		/// @param event Events to store the event polled
		/// @return Returns true if there is an event to be handled or false if there is no event that frame
		bool PollEvent(sf::Event &event);

		/// @brief Renders objects to the screen
		void Render();

		/// @brief Closes the game window, ending the program
		void Close();

		/// @brief Gets the size of the window
		/// @return Size of the window
		std::pair<unsigned int, unsigned int> GetSize();

		/// @brief
		/// @return
		std::string GetTitle();

	private:
		sf::RenderWindow *m_Window;

		unsigned int m_Width, m_Height;
		std::string m_Title;
	};
}