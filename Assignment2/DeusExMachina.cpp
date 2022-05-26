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
		for (unsigned i = 0; i < mSize; ++i)
		{
			mVehicles[i]->Transform(mVehicles[i]->GetMaxSpeed());
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mSize >= 10)
			return false;
		Vehicle** updatedVehicles = new Vehicle* [mSize + 1];
		for (unsigned i = 0; i < mSize; ++i)
			updatedVehicles[i] = mVehicles[i];
		updatedVehicles[mSize++] = vehicle;
		delete[] mVehicles;
		mVehicles = updatedVehicles;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mSize)
			return false;

		delete mVehicles[i];
		mVehicles[i] = nullptr;

		auto**   next = new Vehicle* [--mSize];
		unsigned idx2 = 0;

		for (unsigned idx = 0; idx <= mSize; ++idx)
		{
			if (mVehicles[idx] != nullptr)
				next[idx2++] = mVehicles[idx];
		}
		delete[] mVehicles;
		mVehicles = next;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mSize == 0)
			return nullptr;

		unsigned       max = 0;
		const Vehicle* vehicle = nullptr;
		for (unsigned i = 0; i < mSize; ++i)
		{
			const auto value = static_cast<unsigned>(fmax(mVehicles[i]->GetDistance(), max));
			if (value > max)
			{
				max = value;
				vehicle = mVehicles[i];
			}
		}
		if (max == 0)
			return nullptr;

		return vehicle;
	}
}
