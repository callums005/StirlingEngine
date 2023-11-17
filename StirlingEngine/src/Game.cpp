#include "Game.h"

namespace StirlingEngine
{
	Game::Game()
	{
		// Generate Core Events
		EventDispatcher::GenerateEvent("OnApplicationStart", EventType::OnApplicationStart);   // 1
		EventDispatcher::GenerateEvent("OnApplicationUpdate", EventType::OnApplicationUpdate); // 2
		EventDispatcher::GenerateEvent("OnApplicationExit", EventType::OnApplicationExit);	   // 3

		EventDispatcher::GenerateEvent("OnWindowClose", EventType::OnWindowClose);	 // 4
		EventDispatcher::GenerateEvent("OnWindowResize", EventType::OnWindowResize); // 5
		EventDispatcher::GenerateEvent("OnWindowMove", EventType::OnWindowMove);	 // 6 // Currently Unused

		EventDispatcher::GenerateEvent("OnMouseDown", EventType::OnMouseDown);	   // 7
		EventDispatcher::GenerateEvent("OnMouseUp", EventType::OnMouseUp);		   // 8
		EventDispatcher::GenerateEvent("OnMouseMove", EventType::OnMouseMove);	   // 9
		EventDispatcher::GenerateEvent("OnMouseScroll", EventType::OnMouseScroll); // 10

		EventDispatcher::GenerateEvent("OnKeyDown", EventType::OnKeyDown); // 11
		EventDispatcher::GenerateEvent("OnKeyUp", EventType::OnKeyUp);	   // 12
	}

	Game::~Game() {}

	void Game::Run()
	{
		// If the debug flag is set, it displays a UI for debugging a game
		if (DebugUIFlag)
		{
			Debug::Log(DebugLevel::Debug, "Debug UI Flag set");
		}

		// Dispatch OnApplicationStart event before calling the OnStart method
		EventDispatcher::DispatchEvent(EventType::OnApplicationStart, "", true);
		OnStart();

		// Sets up the input system defaulting variables ect.
		Input::Init();

		// Main game loop, only stops when the window is closed
		while (m_Window->IsOpen())
		{
			EventDispatcher::DispatchEvent(EventType::OnApplicationUpdate, "", true);

			EntityManager::Update();

			// Event handling, creating a custom API for the SFML event system
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
			}

			// Starts rendering the window
			m_Window->Render();

			OnUpdate();

			// Updates the input states
			Input::Update();
		}

		// Dispatched when the application is closed, called bfore the OnExit method
		EventDispatcher::DispatchEvent(EventType::OnApplicationExit, "", true);
		OnExit();
	}

	Window *Game::GetWindow()
	{
		return m_Window;
	}

	//
	void Game::SetWindow(unsigned int width, unsigned int height, std::string title, bool override)
	{
		if (override)
			m_Window = new Window(width, height, title);
		else if (title != "Default Window Settings - Call SetWindow() in constructor")
			Debug::Log(StirlingEngine::Warning, "Unable to create window called: \"%s\", you must set override to true", title.c_str());
	}

	std::pair<unsigned int, unsigned int> Game::GetWindowSize()
	{
		return m_Window->GetSize();
	}
}