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

	void Game::SetWindow()
	{
		m_Window = new Window(400, 400, "Hello World");
	}

	std::pair<unsigned int, unsigned int> Game::GetWindowSize()
	{
		return m_Window->GetSize();
	}
}