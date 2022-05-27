#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& other);
		Vehicle& operator=(const Vehicle& other);
		virtual  ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool            AddPassenger(const Person* person);
		bool            RemovePassenger(unsigned int i);
		const Person*   GetPassenger(unsigned int i) const;
		unsigned int    GetPassengersCount() const;
		unsigned int    GetMaxPassengersCount() const;
		unsigned        GetPassengerWeight() const;
		void            Travel(unsigned distance);
		inline unsigned GetDistance() const;
		inline void     Clear();

	protected:
		unsigned mInterval;
		unsigned mActive;

	private:
		unsigned       mTravel;
		unsigned       mDistance;
		unsigned       mMaxPassengerCount;
		unsigned       mPassengerCount;
		const Person** mPassenger;
	};

	unsigned Vehicle::GetDistance() const
	{
		return mDistance;
	}
	inline void Vehicle::Clear()
	{
		for (unsigned i = 0; i < mMaxPassengerCount; ++i)
		{
			if (mPassenger[i] != nullptr)
			{
				mPassenger[i] = nullptr;
			}
		}
		mPassengerCount = 0;
	}

}
