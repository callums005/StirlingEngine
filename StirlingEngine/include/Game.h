#pragma once

#include "Window.h"
#include "ECS/EntityManager.h"
#include "Events/EventDispatcher.h"
#include "Input.h"

#include "Debug.h"

namespace StirlingEngine
{
	class Game
	{
	public:
		Game();
		~Game();

		void Run();

		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnExit() = 0;

		/// @brief Allows the game client to create the window
		/// @param width Width of the window
		/// @param height Height of the window
		/// @param title Title of the window
		void SetWindow(unsigned int width, unsigned int height, std::string title, bool override = true);

		/// @brief Gets the window class
		/// @return Window class
		Window *GetWindow();

		/// @brief Gets the window size
		/// @return The size of the window
		std::pair<unsigned int, unsigned int> GetWindowSize();

		bool DebugUIFlag = false;

	private:
		Window *m_Window = nullptr;
	};

	// Defined on game side
	Game *CreateGame();
}