#include "Boat.h"

#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		:Vehicle(maxPassengersCount)
	{
		mInterval = 3;
		mActive = 2;
	}

	Boat::~Boat()
	{
	}

	unsigned Boat::GetSailSpeed() const
	{
		const double speed = fmax(800 - (10 * GetTotalWeight()), 20);
		return static_cast<unsigned>(round(speed));
	}

	unsigned Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		const unsigned airCount = plane.GetPassengersCount();
		const unsigned boatCount = GetPassengersCount();

		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		/// 승객을 옮겨줄 것
		/// 1. 비행기 승객부터
		for (unsigned i = 0; i < airCount; ++i)
		{
			const Person* passenger = plane.GetPassenger(0);
			bp.AddPassenger(passenger);
			plane.Migrate(0);
		}

		/// 2. 보트 승객
		for (unsigned i = 0; i <boatCount; ++i)
		{
			const Person* passenger = GetPassenger(0);
			bp.AddPassenger(passenger);
			Migrate(0);
		}

		return bp;
	}
}
