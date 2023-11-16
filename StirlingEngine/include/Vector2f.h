#pragma once

namespace StirlingEngine
{
	class Vector2f
	{
	public:
		float x = 0;
		float y = 0;

		Vector2f()
		{
		}

		Vector2f(float x_in, float y_in)
			: x(x_in), y(y_in)
		{
		}

		Vector2f operator+(const Vector2f &rhs) const
		{
			return Vector2f(x + rhs.x, y + rhs.y);
		}

		Vector2f operator-(const Vector2f &rhs) const
		{
			return Vector2f(x - rhs.x, y - rhs.y);
		}

		Vector2f operator*(const float scale) const
		{
			return Vector2f(x * scale, y * scale);
		}

		Vector2f operator*(const Vector2f scale) const
		{
			return Vector2f(x * scale.x, y * scale.y);
		}

		void operator+=(const Vector2f &rhs)
		{
			x += rhs.x;
			y += rhs.y;
		}

		void operator-=(const Vector2f &rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
		}

		std::string ToString()
		{
			std::string result = "";

			std::string xs = std::to_string(x);
			std::string ys = std::to_string(y);

			result += "Vector2f: [ X: ";
			result += xs;
			result += ", ";
			result += "Y: ";
			result += ys + " ]";

			return result;
		}
	};
}