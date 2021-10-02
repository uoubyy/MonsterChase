#include "point2.h"
namespace Engine {
	Point2 operator+(const Point2& lhs, const Point2& rhs) {
		return Point2(lhs.X() + rhs.X(), lhs.Y() + rhs.Y());
	}

	Point2 operator-(const Point2& lhs, const Point2& rhs) {
		return Point2(lhs.X() - rhs.X(), lhs.Y() - rhs.Y());
	}

	Point2 operator*(const Point2& lhs, const Point2& rhs) {
		return Point2(lhs.X() * rhs.X(), lhs.Y() * rhs.Y());
	}

	bool operator==(const Point2& lhs, const Point2& rhs) {
		return (lhs.X() == rhs.X() && lhs.Y() == rhs.Y());
	}

	bool operator!=(const Point2& lhs, const Point2& rhs)
	{
		return !(lhs == rhs);
	}

	Point2 operator*(const Point2& lhs, int value)
	{
		return Point2(lhs.X() * value, lhs.Y() * value);
	}

	Point2 operator*(int value, const Point2& rhs)
	{
		return rhs * value;
	}

	Point2 operator/(const Point2& lhs, int value)
	{
		return Point2(lhs.X() / value, lhs.Y() / value);
	}
}