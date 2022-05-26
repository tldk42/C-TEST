#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mCapacity(maxPassengersCount),
		  mPassengerCount(0),
		  mDistance(0),
		  mTraveledTime(0),
		  mPassengers(nullptr)
	{
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mCapacity(other.mCapacity),
		  mPassengerCount(other.mPassengerCount),
		  mDistance(0),
		  mTraveledTime(0),
		  mPassengers(new const Person* [mPassengerCount])
	{
		for (unsigned i = 0; i < mPassengerCount; ++i)
		{
			mPassengers[i] = other.mPassengers[i];
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (mPassengers == other.mPassengers)
			return *this;
		delete[] mPassengers;
		mCapacity = other.mCapacity;
		mPassengerCount = other.mPassengerCount;
		mDistance = other.mDistance;
		mTraveledTime = other.mTraveledTime;
		mPassengers = new const Person* [mPassengerCount];
		mInterval = other.mInterval;
		mActive = other.mActive;
		for (unsigned i = 0; i < mPassengerCount; ++i)
			mPassengers[i] = other.mPassengers[i];
		return *this;
	}

	Vehicle::~Vehicle()
	{
		for (unsigned i = 0; i < mPassengerCount; ++i)
			delete mPassengers[i];
		delete[] mPassengers;
	}

	void Vehicle::Transform(unsigned distance)
	{
		// 가동할 수 있는 기간이라면 가동
		if ((mTraveledTime % mInterval) < mActive)
		{
			mDistance += distance;
		}
		mTraveledTime++;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengerCount >= mCapacity)
			return false;

		const auto** next = new const Person* [mPassengerCount + 1];

		for (unsigned i = 0; i < mPassengerCount; ++i)
		{
			next[i] = mPassengers[i];
		}
		next[mPassengerCount++] = person;
		delete[] mPassengers;
		mPassengers = next;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPassengerCount <= i)
			return false;

		delete mPassengers[i];
		mPassengers[i] = nullptr;

		const auto** next = new const Person* [--mPassengerCount];
		unsigned     idx2 = 0;

		for (unsigned idx = 0; idx <= mPassengerCount; ++idx)
		{
			if (mPassengers[idx] != nullptr)
				next[idx2++] = mPassengers[idx];
		}
		delete[] mPassengers;
		mPassengers = next;
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mCapacity;
	}

	void Vehicle::Migrate(unsigned i)
	{
		const auto** updatedPassengers = new const Person* [--mPassengerCount];
		unsigned     idx2 = 0;
		for (unsigned idx = 0; idx <= mPassengerCount; ++idx)
		{
			if (idx != i)
				updatedPassengers[idx2++] = mPassengers[idx];
		}
		delete[] mPassengers;
		mPassengers = updatedPassengers;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengerCount <= i)
			return nullptr;
		return mPassengers[i];
	}
}
