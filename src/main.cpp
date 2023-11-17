#include "StirlingEngine.h"

class Sandbox : public StirlingEngine::Game
{
public:
	Sandbox()
	{
		SetWindow(400, 400, "Sandbox");

		DebugUIFlag = true;
	}
	~Sandbox()
	{
	}

	void OnStart()
	{
		StirlingEngine::Entity *e = StirlingEngine::EntityManager::CreateEntity("res/TestEntity.see");
		StirlingEngine::Debug::Log("%s", e->ToString().c_str());
	}

	void OnUpdate()
	{
	}
	void OnExit() {}
};

// Defined engine side
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}