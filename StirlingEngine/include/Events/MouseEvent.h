#pragma once

namespace StirlingEngine
{
	struct MouseMoveEvent
	{
		int MouseX = 0;
		int MouseY = 0;
	};

	struct MouseButtonEvent
	{
		int MouseButton = -1;
		bool State = false;
	};

	struct MouseSctrollEvent
	{
		double OffsetX = 0;
		double OffsetY = 0;
	};
}