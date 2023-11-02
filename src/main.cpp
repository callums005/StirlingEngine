#include <stdio.h>
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

	void OnStart()
	{
		printf("Start\n");
	}
	void OnUpdate() {}
	void OnExit() {}
};

// Defined engine side
StirlingEngine::Game *StirlingEngine::CreateGame()
{
	return new Sandbox();
}