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

			std::string sizexs = dh->GetValueFromScope("transform/size", "x");
			int sizex = 0;
			if (sizexs != "NULL")
				sizex = std::stoi(sizexs);
			Size.x = sizex;

			std::string sizeys = dh->GetValueFromScope("transform/size", "y");
			int sizey = 0;
			if (sizeys != "NULL")
				sizey = std::stoi(sizeys);
			Size.y = sizey;

			std::string velxs = dh->GetValueFromScope("transform/velocity", "x");
			int velx = 0;
			if (velxs != "NULL")
				velx = std::stoi(velxs);
			Velocity.x = velx;

			std::string velys = dh->GetValueFromScope("transform/velocity", "y");
			int vely = 0;
			if (velys != "NULL")
				vely = std::stoi(velys);
			Velocity.y = vely;
		}

		std::string ToString()
		{
			std::string result = "";

			result += "cTransform\n";
			result += "Positon: ";
			result += Position.ToString() + "\t";
			result += "Size: ";
			result += Size.ToString() += "\t";
			result += "Velocity: ";
			result += Velocity.ToString() += "\t";

			return result;
		}

		Vector2i Position;
		Vector2i Size;
		Vector2i Velocity;
	};
}