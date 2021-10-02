#ifndef POINT2_H
#define POINT2_H
namespace Engine {
	class Point2
	{
	public:
		Point2(int _x, int _y) :x(_x), y(_y) {};

		int X() const { return x; }
		int Y() const { return y; }

		void SetX(int _x) { x = _x; }
		void SetY(int _y) { y = _y; }

		Point2 operator-() {
			return Point2(-x, -y);
		}

		Point2& operator+=(const Point2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		Point2& operator-=(const Point2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		Point2& operator*=(const Point2& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}

		Point2& operator*=(int value) {
			x *= value;
			y *= value;
			return *this;
		}

		Point2& operator/=(int value) {
			x /= value;
			y /= value;
			return *this;
		}

	private:
		int x;
		int y;
	};

	using Vector2 = Point2;

	Point2 operator+(const Point2& lhs, const Point2& rhs);

	Point2 operator-(const Point2& lhs, const Point2& rhs);

	Point2 operator*(const Point2& lhs, const Point2& rhs);

	Point2 operator*(const Point2& lhs, int value);

	Point2 operator*(int value, const Point2& rhs);

	Point2 operator/(const Point2& lhs, int value);

	bool operator==(const Point2& lhs, const Point2& rhs);

	bool operator!=(const Point2& lhs, const Point2& rhs);
}
#endif // POINT2_H