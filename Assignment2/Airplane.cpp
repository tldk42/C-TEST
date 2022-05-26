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
		const double speed = 200 * exp((800.0 - GetTotalWeight()) / 500.0);
		return static_cast<unsigned>(round(speed));
	}

	unsigned Airplane::GetFlySpeed() const
	{
		const double speed = 4 * exp((400.0 - GetTotalWeight()) / 70.0);
		return static_cast<unsigned>(round(speed));
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
			const Person* passenger = GetPassenger(0);
			bp.AddPassenger(passenger);
			Migrate(0);
		}

		/// 2. 보트 승객
		for (unsigned i = 0; i < boatCount; ++i)
		{
			const Person* passenger = boat.GetPassenger(0);
			bp.AddPassenger(passenger);
			boat.Migrate(0);
		}

		return bp;
	}
}
