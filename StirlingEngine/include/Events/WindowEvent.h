#pragma once

namespace StirlingEngine
{
	struct WindowMoveEvent
	{
		int XPos = 0;
		int YPos = 0;
	};

	struct WindowResizeEvent
	{
		int Width = 0;
		int Height = 0;
	};
}