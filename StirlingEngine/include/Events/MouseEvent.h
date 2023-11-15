#pragma once

namespace StirlingEngine
{
	/// @brief Stores information about the mouse position for the event
	struct MouseMoveEvent
	{
		int MouseX = 0;
		int MouseY = 0;
	};

	/// @brief Stores information about the mouse button state for the event
	struct MouseButtonEvent
	{
		int MouseButton = -1;
		bool State = false;
	};

	/// @brief Stores information about the mouse scroll wheel for the event
	struct MouseSctrollEvent
	{
		double OffsetX = 0;
		double OffsetY = 0;
	};
}