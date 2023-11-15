#pragma once

namespace StirlingEngine
{
	/// @brief Stores information about the key that triggers the event.
	struct KeyEvent
	{
		int KeyCode = -1;
		bool State = false;
		bool ShiftMod = false;
		bool ControlMod = false;
		bool AltMod = false;
	};
}