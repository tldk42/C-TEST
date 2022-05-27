#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mInterval(0),
		  mActive(0),
		  mTravel(0),
		  mDistance(0),
		  mMaxPassengerCount(maxPassengersCount),
		  mPassengerCount(0)
	{
		mPassenger = new const Person* [mMaxPassengerCount];
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mInterval(other.mInterval),
		  mActive(other.mActive),
		  mTravel(other.mTravel),
		  mDistance(other.mDistance),
		  mMaxPassengerCount(other.mMaxPassengerCount),
		  mPassengerCount(other.mPassengerCount)
	{
		mPassenger = new const Person* [mMaxPassengerCount];
		for (unsigned i = 0; i < mPassengerCount; ++i)
		{
			mPassenger[i] = other.mPassenger[i];
			other.mPassenger[i] = new Person(*mPassenger[i]);
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (mPassenger == other.mPassenger)
			return *this;
		for (unsigned i = 0; i < mPassengerCount; ++i)
			delete mPassenger[i];
		delete[] mPassenger;
		mInterval = other.mInterval;
		mActive = other.mActive;
		mTravel = other.mTravel;
		mDistance = other.mDistance;
		mMaxPassengerCount = other.mMaxPassengerCount;
		mPassengerCount = other.mPassengerCount;
		mPassenger = new const Person* [mMaxPassengerCount];
		for (unsigned i = 0; i < mPassengerCount; ++i)
		{
			mPassenger[i] = other.mPassenger[i];
			other.mPassenger[i] = new Person(*mPassenger[i]);
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		for (unsigned i = 0; i < mPassengerCount; ++i)
			delete mPassenger[i];
		delete[] mPassenger;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if ((mPassengerCount >= mMaxPassengerCount) || person == nullptr)
			return false;
		for (unsigned i = 0; i < mPassengerCount; ++i)
		{
			if (mPassenger[i] == person)
				return false;
		}
		mPassenger[mPassengerCount++] = person;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPassengerCount <= i)
			return false;
		delete mPassenger[i];
		for (unsigned idx = i; idx < mPassengerCount - 1; ++idx)
		{
			mPassenger[idx] = mPassenger[idx + 1];
		}
		mPassenger[--mPassengerCount] = nullptr;
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengerCount;
	}

	unsigned Vehicle::GetPassengerWeight() const
	{
		unsigned totalWeight = 0;
		for (unsigned i = 0; i < mPassengerCount; ++i)
			totalWeight += mPassenger[i]->GetWeight();
		return totalWeight;
	}

	void Vehicle::Travel(unsigned distance)
	{
		if (mTravel++ % mInterval < mActive)
		{
			mDistance += distance;
		}
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengerCount <= i)
			return nullptr;
		return mPassenger[i];
	}
}
