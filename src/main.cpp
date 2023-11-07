#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}

	void OnStart() {
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Info, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Debug, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Warning, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Error, "Hello World");
		StirlingEngine::Debug::Log(StirlingEngine::DebugLevel::Critical, "Hello World");
		StirlingEngine::Debug::Log((StirlingEngine::DebugLevel)5, "Hello World");
	}
	void OnUpdate() {}
	void OnExit() {}
};

// Defined engine side
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}