#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		mInterval = 4;
		mActive = 1;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned Boatplane::GetFlySpeed() const
	{
		return static_cast<unsigned>(round(150 * exp((500.0 - GetPassengerWeight()) / 300)));
	}

	unsigned Boatplane::GetSailSpeed() const
	{
		return static_cast<unsigned>(round(fmax(800.0 - (1.7 * GetPassengerWeight()), 20)));
	}

	unsigned Boatplane::GetMaxSpeed() const
	{
		return GetFlySpeed() > GetSailSpeed() ? GetFlySpeed() : GetSailSpeed();
	}
}
