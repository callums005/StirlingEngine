#include "Game.h"

namespace StirlingEngine
{
	Game::Game()
	{
		// Generate Events
		EventDispatcher::GenerateEvent("OnApplicationStart", EventType::OnApplicationStart);
		EventDispatcher::GenerateEvent("OnApplicationUpdate", EventType::OnApplicationUpdate);
		EventDispatcher::GenerateEvent("OnApplicationExit", EventType::OnApplicationExit);

		EventDispatcher::GenerateEvent("OnWindowClose", EventType::OnWindowClose);
		EventDispatcher::GenerateEvent("OnWindowResize", EventType::OnWindowResize);
		EventDispatcher::GenerateEvent("OnWindowMove", EventType::OnWindowMove);

		EventDispatcher::GenerateEvent("OnMouseDown", EventType::OnMouseDown);
		EventDispatcher::GenerateEvent("OnMouseUp", EventType::OnMouseUp);
		EventDispatcher::GenerateEvent("OnMouseMove", EventType::OnMouseMove);
		EventDispatcher::GenerateEvent("OnMouseScroll", EventType::OnMouseScroll);

		EventDispatcher::GenerateEvent("OnKeyDown", EventType::OnKeyDown);
		EventDispatcher::GenerateEvent("OnKeyUp", EventType::OnKeyUp);
	}

	Game::~Game() {}

	void Game::Run()
	{
		EventDispatcher::DispatchEvent(EventType::OnApplicationStart, "", true);
		OnStart();

		while (m_Window->IsOpen())
		{
			EventDispatcher::DispatchEvent(EventType::OnApplicationUpdate, "", true);
			OnUpdate();

			sf::Event e;

			while (m_Window->PollEvent(e))
			{
				switch (e.type)
				{
				case sf::Event::Closed:
					EventDispatcher::DispatchEvent(EventType::OnWindowClose);
					m_Window->Close();
					break;
				case sf::Event::Resized:
					EventDispatcher::GetEventByName("OnWindowResize").OnWindowResizeEvent->Width = e.size.width;
					EventDispatcher::GetEventByName("OnWindowResize").OnWindowResizeEvent->Height = e.size.height;
					EventDispatcher::DispatchEvent(EventType::OnWindowResize);
					break;
				case sf::Event::MouseMoved:
					EventDispatcher::GetEventByName("OnMouseMove").OnMouseMoveEvent->MouseX = e.mouseMove.x;
					EventDispatcher::GetEventByName("OnMouseMove").OnMouseMoveEvent->MouseY = e.mouseMove.y;
					EventDispatcher::DispatchEvent(EventType::OnMouseMove);
					break;
				case sf::Event::MouseButtonPressed:
					EventDispatcher::GetEventByName("OnMouseDown").OnMouseButtonEvent->State = true;
					EventDispatcher::GetEventByName("OnMouseDown").OnMouseButtonEvent->MouseButton = (int)e.mouseButton.button;
					EventDispatcher::DispatchEvent(EventType::OnMouseDown);
					break;
				case sf::Event::MouseButtonReleased:
					EventDispatcher::GetEventByName("OnMouseUp").OnMouseButtonEvent->State = false;
					EventDispatcher::GetEventByName("OnMouseUp").OnMouseButtonEvent->MouseButton = (int)e.mouseButton.button;
					EventDispatcher::DispatchEvent(EventType::OnMouseUp);
					break;
				case sf::Event::MouseWheelScrolled:
					EventDispatcher::GetEventByName("OnMouseScroll").OnMouseScrollEvent->OffsetX = e.mouseWheel.x;
					EventDispatcher::GetEventByName("OnMouseScroll").OnMouseScrollEvent->OffsetY = e.mouseWheel.y;
					EventDispatcher::DispatchEvent(EventType::OnMouseScroll);
					break;
				case sf::Event::KeyPressed:
					EventDispatcher::GetEventByName("OnKeyDown").OnKeyEvent->State = true;
					EventDispatcher::GetEventByName("OnKeyDown").OnKeyEvent->KeyCode = (int)e.key.code;
					EventDispatcher::GetEventByName("OnKeyDown").OnKeyEvent->ShiftMod = e.key.shift;
					EventDispatcher::GetEventByName("OnKeyDown").OnKeyEvent->ControlMod = e.key.control;
					EventDispatcher::GetEventByName("OnKeyDown").OnKeyEvent->AltMod = e.key.alt;
					EventDispatcher::DispatchEvent(EventType::OnKeyDown);
					break;
				case sf::Event::KeyReleased:
					EventDispatcher::GetEventByName("OnKeyUp").OnKeyEvent->State = false;
					EventDispatcher::GetEventByName("OnKeyUp").OnKeyEvent->KeyCode = (int)e.key.code;
					EventDispatcher::GetEventByName("OnKeyUp").OnKeyEvent->ShiftMod = e.key.shift;
					EventDispatcher::GetEventByName("OnKeyUp").OnKeyEvent->ControlMod = e.key.control;
					EventDispatcher::GetEventByName("OnKeyUp").OnKeyEvent->AltMod = e.key.alt;
					EventDispatcher::DispatchEvent(EventType::OnKeyUp);
					break;
				}

				if (e.type == sf::Event::Closed)
					m_Window->Close();
			}

			m_Window->Render();
		}

		EventDispatcher::DispatchEvent(EventType::OnApplicationExit, "", true);
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