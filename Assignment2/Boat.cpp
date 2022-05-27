#include "Boat.h"

#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		mInterval = 3;
		mActive = 2;
	}

	Boat::~Boat()
	{
	}

	unsigned Boat::GetSailSpeed() const
	{
		return static_cast<unsigned>(fmax(800.0 - 10 * GetPassengerWeight(), 20.0));
	}

	unsigned Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		for (unsigned i = 0; i < plane.GetPassengersCount(); ++i)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}
		
		for (unsigned i = 0; i < GetPassengersCount(); ++i)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		plane.Clear();
		Clear();
		return bp;
	}
}
