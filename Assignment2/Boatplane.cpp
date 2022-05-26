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
		return static_cast<unsigned>(round(150 * exp((500.f - GetTotalWeight()) / 300)));
	}

	unsigned Boatplane::GetSailSpeed() const
	{
		return static_cast<unsigned>(round(fmax(800.f - (1.7 * GetTotalWeight()), 20)));
	}

	unsigned Boatplane::GetMaxSpeed() const
	{
		return GetSailSpeed() > GetFlySpeed() ? GetSailSpeed() : GetFlySpeed();
	}
	
}
