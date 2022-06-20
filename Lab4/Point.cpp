#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x),
		  mY(y)
	{
	}

	Point Point::operator+(const Point& other) const
	{
		return {this->mX + other.mX, this->mY + other.mY};
	}

	Point Point::operator-(const Point& other) const
	{
		return {this->mX - other.mX, this->mY - other.mY};
	}

	float Point::Dot(const Point& other) const
	{
		return (this->mX * other.mX + this->mY * other.mY);
	}

	Point Point::operator*(float operand) const
	{
		return {this->mX * operand, this->mY * operand};;
	}

	Point operator*(float operand, const Point& point)
	{
		return {operand * point.mX, operand * point.mY};
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}
