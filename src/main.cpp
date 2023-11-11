#include "StirlingEngine.h"

#include <iostream>

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}

	void LogKeyPress(StirlingEngine::Event &e)
	{
		StirlingEngine::Debug::Log("KEY PRESSED: %i", e.OnKeyEvent->KeyCode);
	}

	void OnStart()
	{
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Info, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Debug, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Warning, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Error, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Critical, "Hello World");
		StirlingEngine::Debug::Log((StirlingEngine::DebugLevel)5, "Hello World");

		StirlingEngine::EventDispatcher::GetEventByName("OnKeyDown") += Subscribe(LogKeyPress);
	}
	void OnUpdate() {}
	void OnExit() {}
};

// Defined engine side
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}