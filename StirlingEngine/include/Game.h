#pragma once

#include "Window.h"

namespace StirlingEngine
{
	class Game
	{
	private:
		Window *m_Window = nullptr;

	public:
		Game();
		~Game();

		void Run();

		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnExit() = 0;

		void SetWindow()
		{
			m_Window = new Window(400, 400, "Hello World");
		}

		Window *GetWindow();
		std::pair<uint, uint> GetWindowSize();
	};

	// Defined on game side
	Game *CreateGame();
};