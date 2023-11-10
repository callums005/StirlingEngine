#pragma once

namespace StirlingEngine
{
	struct KeyEvent
	{
		int KeyCode = -1;
		bool State = false;
		bool ShiftMod = false;
		bool ControlMod = false;
		bool AltMod = false;
	};
}