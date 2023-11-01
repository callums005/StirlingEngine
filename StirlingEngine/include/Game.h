#pragma once

namespace StirlingEngine
{
	class Game
	{
	public:
		Game();
		~Game();

		void Run();
		
		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnExit() = 0;
	};

	// Defined on game side
	Game* CreateGame();
};