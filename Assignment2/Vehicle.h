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
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;
		virtual void         Transform(unsigned distance);

		bool          AddPassenger(const Person* person);
		bool          RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int  GetPassengersCount() const;
		unsigned int  GetMaxPassengersCount() const;

		unsigned GetTotalWeight() const;
		inline unsigned GetDistance() const;
		void            Migrate(unsigned i);

	private:
		unsigned       mCapacity;
		unsigned       mPassengerCount;
		unsigned       mDistance;
		unsigned       mTraveledTime;
		const Person** mPassengers;

	protected:
		unsigned mInterval;
		unsigned mActive;
	};

	inline unsigned Vehicle::GetDistance() const
	{
		return mDistance;
	}
	
}
