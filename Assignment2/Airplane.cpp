#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		mInterval = 4;
		mActive = 1;
	}

	Airplane::~Airplane()
	{
	}
	
	unsigned Airplane::GetMaxSpeed() const
	{
		return GetDriveSpeed() > GetFlySpeed() ? GetDriveSpeed() : GetFlySpeed();
	}

	unsigned Airplane::GetDriveSpeed() const
	{
		return static_cast<unsigned>(round(200 * exp((800.0 - GetTotalWeight()) / 500.0)));
	}

	unsigned Airplane::GetFlySpeed() const
	{
		return static_cast<unsigned>(round(4 * exp((400.0 - GetTotalWeight()) / 70.0)));
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		const unsigned airCount = GetPassengersCount();
		const unsigned boatCount = boat.GetPassengersCount();

		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());
		
		/// 승객을 옮겨줄 것
		/// 1. 비행기 승객부터
		for (unsigned i = 0; i < airCount; ++i)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		
		/// 2. 보트 승객
		for (unsigned i = 0; i < boatCount; ++i)
		{
			bp.AddPassenger(boat.GetPassenger(i));
		}

		Migrate();
		boat.Migrate();

		return Boatplane(bp);
	}
}
