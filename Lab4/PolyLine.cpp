#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPoints(new Point[10]),
		  mSize(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mPoints(new Point[10]),
		  mSize(other.mSize)
	{
		for (unsigned i = 0; i < mSize; ++i)
		{
			mPoints[i] = other.mPoints[i];
		}
	}

	PolyLine::~PolyLine()
	{
		delete[] mPoints;
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (mPoints == other.mPoints)
			return *this;
		mSize = other.mSize;
		for (unsigned i = 0; i < mSize; ++i)
		{
			mPoints[i] = other.mPoints[i];
		}
		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 10)
			return false;
		mPoints[mSize++] = Point(x, y);
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= 10 || point == nullptr)
			return false;
		mPoints[mSize++] = *point;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize)
			return false;

		for (unsigned idx = i; idx < mSize; ++idx)
		{
			if (i == 9)
				break;
			mPoints[idx] = mPoints[idx + 1];
		}
		mSize --;
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize < 2)
			return false;
		float minX = mPoints[0].GetX();
		float minY = mPoints[0].GetY();
		float maxX = mPoints[0].GetX();
		float maxY = mPoints[0].GetY();
		for (unsigned i = 1; i < mSize; ++i)
		{
			if (minX > mPoints[i].GetX())
				minX = mPoints[i].GetX();
			if (minY > mPoints[i].GetY())
				minY = mPoints[i].GetY();
			if (maxX < mPoints[i].GetX())
				maxX = mPoints[i].GetX();
			if (maxY < mPoints[i].GetY())
				maxY = mPoints[i].GetY();
		}
		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);
		if (minX == maxX || minY == maxY)
			return false;
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize)
			return nullptr;
		return new Point(mPoints[i].GetX(), mPoints[i].GetY());
	}
}
