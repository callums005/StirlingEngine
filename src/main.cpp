#include "StirlingEngine.h"

#include "SEDataHandler.h"

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
		// StirlingEngine::SEDataHandler *dataHandler = new StirlingEngine::SEDataHandler("res/TestEntity.see");
		// StirlingEngine::Debug::Log("%s", dataHandler->GetValueFromScope("transform/position", "x").c_str());

		StirlingEngine::Entity *e = new StirlingEngine::Entity("res/TestEntity.see");
		StirlingEngine::Debug::Log("Position X: %i | Position Y: %i", e->Transform->Position.x, e->Transform->Position.y);
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