#pragma once

namespace lab4
{
	/**
	 * \brief Point 클래스는 2D 좌표이다.
	 *	기본 자료형인 float형 변수 x, y를 멤버변수로 가진다.
	 *	따라서 복사생성자, 대입연산자는 필요치 않다.
	 *	멤버함수로는 연산자 오버로딩, x, y좌표를 반환하는 함수이다.
	 */
	class Point
	{
	public:
		Point(float x, float y);

		Point        operator+(const Point& other) const;
		Point        operator-(const Point& other) const;
		float        Dot(const Point& other) const;
		Point        operator*(float operand) const;
		friend Point operator*(float operand, const Point& point);
		float        GetX() const;
		float        GetY() const;

	private:
		float mX;
		float mY;
	};
}
