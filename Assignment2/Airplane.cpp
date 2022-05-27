#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned Airplane::GetDriveSpeed() const
	{
		return static_cast<unsigned>(4 * exp((400.0 - GetPassengerWeight()) / 70.0));
	}

	unsigned Airplane::GetFlySpeed() const
	{
		return static_cast<unsigned>(200 * exp(800.0 - GetPassengerWeight()) / 500.0);
	}

	unsigned Airplane::GetMaxSpeed() const
	{
		return GetFlySpeed() > GetDriveSpeed() ? GetFlySpeed() : GetDriveSpeed();
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		for (unsigned i = 0; i < GetPassengersCount(); ++i)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		for (unsigned i = 0; i < boat.GetPassengersCount(); ++i)
		{
			bp.AddPassenger(boat.GetPassenger(i));
		}
		return bp;
	}
}
