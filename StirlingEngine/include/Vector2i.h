#pragma once

#include <string>

namespace StirlingEngine
{
	class Vector2i
	{
	public:
		int x = 0;
		int y = 0;

		Vector2i()
		{
		}

		Vector2i(int x_in, int y_in)
			: x(x_in), y(y_in)
		{
		}

		Vector2i operator+(const Vector2i &rhs) const
		{
			return Vector2i(x + rhs.x, y + rhs.y);
		}

		Vector2i operator-(const Vector2i &rhs) const
		{
			return Vector2i(x - rhs.x, y - rhs.y);
		}

		Vector2i operator*(const int scale) const
		{
			return Vector2i(x * scale, y * scale);
		}

		Vector2i operator*(const Vector2i scale) const
		{
			return Vector2i(x * scale.x, y * scale.y);
		}

		void operator+=(const Vector2i &rhs)
		{
			x += rhs.x;
			y += rhs.y;
		}

		void operator-=(const Vector2i &rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
		}

		std::string ToString()
		{
			std::string result = "";

			std::string xs = std::to_string(x);
			std::string ys = std::to_string(y);

			result += "Vector2i: [ X: ";
			result += xs;
			result += ", ";
			result += "Y: ";
			result += ys + " ]";

			return result;
		}
	};
}