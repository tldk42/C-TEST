#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned Boatplane::GetFlySpeed() const
	{
		return static_cast<unsigned>(150.0 * exp(500 - GetPassengerWeight()) / 300.0);
	}

	unsigned Boatplane::GetSailSpeed() const
	{
		return static_cast<unsigned>(fmax(800 - 1.7 * GetPassengerWeight(), 20.0));
	}

	unsigned Boatplane::GetMaxSpeed() const
	{
		return GetFlySpeed() > GetSailSpeed() ? GetFlySpeed() : GetSailSpeed();
	}
}
