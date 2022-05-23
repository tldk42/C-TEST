#include "Point.h"

namespace lab4
{
	Point::Point()
	{
	}

	Point::Point(float x, float y)
		: mX(x),
		  mY(y)
	{
	}

	Point::~Point()
	{
	}

	// Point& Point::operator= (const Point& other)
	// {
	// 	mX = other.mX;
	// 	mY = other.mY;
	// 	return *this;
	// }


	Point Point::operator+(const Point& other) const
	{
		auto nPoint = Point(this->mX + other.mX, this->mY + other.mY);
		return nPoint;
	}

	Point Point::operator-(const Point& other) const
	{
		auto nPoint = Point(this->mX - other.mX, this->mY - other.mY);
		return nPoint;
	}

	float Point::Dot(const Point& other) const
	{
		float dotX = this->mX * other.mX;
		float dotY = this->mY * other.mY;
		return (dotX + dotY);
	}

	Point Point::operator*(float operand) const
	{
		auto nPoint = Point(this->mX * operand, this->mY * operand);
		return nPoint;
	}

	Point operator*(float operand, const Point& point)
	{
		auto nPoint = Point(operand * point.mX, operand * point.mY);
		return nPoint;
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
