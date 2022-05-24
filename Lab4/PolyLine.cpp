#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPoint(nullptr),
		  mSize(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mPoint(),
		  mSize(other.mSize)
	{
		mPoint = new const Point* [mSize];
		for (unsigned i = 0; i < mSize; ++i)
			mPoint[i] = new Point(other.mPoint[i]->GetX(), other.mPoint[i]->GetY());
	}

	PolyLine::~PolyLine()
	{
		for (unsigned i = 0; i < mSize; ++i)
			delete mPoint[i];
		delete mPoint;
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		mSize = other.mSize;
		mPoint = new const Point* [mSize];
		for (unsigned i = 0; i < mSize; ++i)
			mPoint[i] = new Point(other.mPoint[i]->GetX(), other.mPoint[i]->GetY());
		return *this;
	}

	/*
	 *점이 PolyLine에 추가되면 true를 반환합니다.
	 *추가된 점의 라이프사이클(수명)은 PolyLine이 관리하지만,
	 *PolyLine 개체를 소멸시키거나 RemovePoint()같은 메서드를 호출하여 점을 소멸시키지 않는 한
	 *여전히 클래스 밖에서도 점을 가리키는 포인터를 사용할 수 있습니다.
	 *만약 PolyLine에 점을 추가할 수 없었다면 false를 반환합니다.
	 */
	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 10)
			return false;
		const auto tempPoints = new const Point* [mSize + 1];
		for (unsigned i = 0; i < mSize; ++i)
		{
			tempPoints[i] = mPoint[i];
		}
		tempPoints[mSize++] = new const Point(x, y);
		delete[] mPoint;
		mPoint = tempPoints;
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= 10 || point == nullptr)
			return false;
		const auto tempPoints = new const Point* [mSize + 1];
		for (unsigned i = 0; i < mSize; ++i)
		{
			tempPoints[i] = mPoint[i];
		}
		tempPoints[mSize++] = point;
		delete[] mPoint;
		mPoint = tempPoints;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize)
			return false;
		delete mPoint[i];
		mPoint[i] = nullptr;
		const auto tempPoints = new const Point* [--mSize];
		unsigned   idx2 = 0;
		for (unsigned idx = 0; idx <= mSize; ++idx)
		{
			if (mPoint[idx] != nullptr)
				tempPoints[idx2++] = mPoint[idx];
		}
		mPoint = tempPoints;
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
