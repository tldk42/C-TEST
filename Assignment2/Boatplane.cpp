#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		:Vehicle(maxPassengersCount)
	{
		mInterval = 4;
		mActive = 1;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned Boatplane::GetFlySpeed() const
	{
		const double speed = 150 * exp((500 - GetTotalWeight()) / 300);
		return static_cast<unsigned>(round(speed));
	}

	unsigned Boatplane::GetSailSpeed() const
	{
		const double speed = fmax(800 - (1.7 * GetTotalWeight()), 20);
		return static_cast<unsigned>(round(speed));
	}

	unsigned Boatplane::GetMaxSpeed() const
	{
		return GetSailSpeed() > GetFlySpeed() ? GetSailSpeed() : GetFlySpeed();
	}
	
}
