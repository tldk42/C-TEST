#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPoint(new const Point*[10]),
		  mSize(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mPoint(new const Point*[10]),
		  mSize(other.mSize)
	{
		for (unsigned i = 0; i < mSize; ++i)
			mPoint[i] = new Point(other.mPoint[i]->GetX(), other.mPoint[i]->GetY());
	}

	PolyLine::~PolyLine()
	{
		for (unsigned i = 0; i < mSize; ++i)
			delete *(mPoint + i);
		delete[] mPoint;
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
			return *this;
		for (unsigned i = 0; i < mSize; ++i)
			delete *(mPoint + i);
		delete[] mPoint;
		mSize = other.mSize;
		mPoint = new const Point*[10];
		for (unsigned i = 0; i < mSize; ++i)
			mPoint[i] = new Point(other.mPoint[i]->GetX(), other.mPoint[i]->GetY());
		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 10)
			return false;
		mPoint[mSize++] = new const Point(x, y);
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= 10 || point == nullptr)
			return false;
		mPoint[mSize++] = point;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize)
			return false;
		delete mPoint[i];
		mPoint[i] = nullptr;

		if (i != mSize - 1)
		{
			for (unsigned idx = i; idx < mSize - 1; ++idx)
			{
				mPoint[idx] = mPoint[idx + 1];
			}
			mPoint[--mSize] = nullptr;
		}
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize == 0)
			return false;

		float minX = mPoint[0]->GetX();
		float minY = mPoint[0]->GetY();
		float maxX = mPoint[0]->GetX();
		float maxY = mPoint[0]->GetY();

		for (unsigned i = 1; i < mSize; ++i)
		{
			minX = fmin(minX, mPoint[i]->GetX());
			minY = fmin(minY, mPoint[i]->GetY());
			maxX = fmax(maxX, mPoint[i]->GetX());
			maxY = fmax(maxY, mPoint[i]->GetY());
		}
		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize)
			return nullptr;
		return mPoint[i];
	}
}
