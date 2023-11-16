#pragma once

#include <string>

#include "../../SEDataHandler.h"

#include "../../Vector2i.h"

namespace StirlingEngine
{
	class cTransform
	{
	public:
		cTransform() {}

		cTransform(SEDataHandler *dh)
		{
			std::string posxs = dh->GetValueFromScope("transform/position", "x");
			int posx = 0;
			if (posxs != "NULL")
				posx = std::stoi(posxs);
			Position.x = posx;

			std::string posys = dh->GetValueFromScope("transform/position", "y");
			int posy = 0;
			if (posys != "NULL")
				posy = std::stoi(posys);
			Position.y = posy;
		}

		Vector2i Position;
		Vector2i Size;
		Vector2i Velocity;
	};
}