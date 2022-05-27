#include "Vehicle.h"
#include <iostream>

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengerCount(maxPassengersCount),
		  mPassengerCount(0),
		  mPassenger(nullptr)
	{
		mPassenger = new const Person*[mMaxPassengerCount];
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengerCount(other.GetMaxPassengersCount()),
		  mPassengerCount(other.mPassengerCount),
		  mPassenger(nullptr)
	{
		mPassenger = new const Person* [mMaxPassengerCount];
		for (unsigned i = 0; i < mPassengerCount; ++i)
			mPassenger[i] = new Person(*other.GetPassenger(i));
		std::cout << "COPY" <<std::endl;
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (mPassenger == other.mPassenger)
			return *this;
		mMaxPassengerCount = other.mMaxPassengerCount;
		mPassengerCount = other.mPassengerCount;
		mPassenger = new const Person* [mMaxPassengerCount];
		for (unsigned i = 0; i < mPassengerCount; ++i)
			mPassenger[i] = new Person(*other.GetPassenger(i));
		std::cout << "=Operator" <<std::endl;
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
		if (mPassengerCount >= mMaxPassengerCount)
			return false;
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
		mPassenger[mPassengerCount--] = nullptr;
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

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengerCount <= i)
			return nullptr;
		return mPassenger[i];
	}
}
