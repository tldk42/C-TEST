#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		// C++11에서 정적 지역변수의 초기화는 멀티스레드 환경에서도 한 번만 수행됨이 보장된다.
		static auto instance = new DeusExMachina();
		return instance;
	}

	void DeusExMachina::Travel() const
	{
		if (mSize == 0)
			return;
		for (unsigned i = 0; i < mSize; ++i)
		{
			mVehicles[i]->Travel(mVehicles[i]->GetMaxSpeed());
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mSize >= 10 || vehicle == nullptr)
			return false;

		for (unsigned i = 0; i < mSize; ++i)
		{
			if (mVehicles[i] == vehicle)
				return false;
		}
		mVehicles[mSize++] = vehicle;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mSize)
			return false;

		delete mVehicles[i];
		for (unsigned idx = i; idx < mSize - 1; ++idx)
		{
			mVehicles[idx] = mVehicles[idx + 1];
		}
		mVehicles[--mSize] = nullptr;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mSize == 0)
			return nullptr;

		unsigned max = 0;
		unsigned maxIdx = 0;
		for (unsigned i = 0; i < mSize; ++i)
		{
			unsigned value = mVehicles[i]->GetDistance();
			if (max < value)
			{
				max = value;
				maxIdx = i;
			}
		}
		if (max == 0)
			return mVehicles[0];
		return mVehicles[maxIdx];
	}
}