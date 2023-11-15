#include "StirlingEngine.h"

#include <iostream>

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