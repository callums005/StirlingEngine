#pragma once

#include "Window.h"
#include "Events/EventDispatcher.h"

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

		void SetWindow();

		Window *GetWindow();
		std::pair<unsigned int, unsigned int> GetWindowSize();

	private:
		Window *m_Window = nullptr;
	};

	// Defined on game side
	Game *CreateGame();
}