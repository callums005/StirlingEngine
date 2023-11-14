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

	void OnStart()
	{
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Info, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Debug, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Warning, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Error, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Critical, "Hello World");
		StirlingEngine::Debug::Log((StirlingEngine::DebugLevel)5, "Hello World");
	}
	void OnUpdate()
	{
		if (StirlingEngine::Input::IsKeyUpThisFrame(StirlingEngine::Key::KEY_SPACE))
			StirlingEngine::Debug::Log("Space bar is released");

		if (StirlingEngine::Input::IsMouseDown(StirlingEngine::MouseButton::MOUSE_BUTTON_LEFT))
			StirlingEngine::Debug::Log("Mouse Down");
	}
	void OnExit() {}
};

// Defined engine side
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}