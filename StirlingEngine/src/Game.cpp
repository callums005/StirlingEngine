#include "Game.h"

namespace StirlingEngine
{
	Game::Game() {}

	Game::~Game() {}

	void Game::Run()
	{
		OnStart();

		while (m_Window->IsOpen())
		{
			OnUpdate();

			sf::Event e;

			while (m_Window->PollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					m_Window->Close();
			}

			m_Window->Render();
		}

		OnExit();
	}

	Window *Game::GetWindow()
	{
		return m_Window;
	}

	std::pair<uint, uint> Game::GetWindowSize()
	{
		return m_Window->GetSize();
	}
}