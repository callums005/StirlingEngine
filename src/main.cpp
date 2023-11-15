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
		StirlingEngine::SEDataHandler *dataHandler = new StirlingEngine::SEDataHandler("res/TestEntity.see");
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