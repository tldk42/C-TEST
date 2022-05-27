#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned>(round((500.0 * log((GetPassengerWeight() + 150.0) / 150.0) + 30.0)));
	}

	unsigned UBoat::GetSailSpeed() const
	{
		return static_cast<unsigned>(round(fmax((550.0 - (GetPassengerWeight() / 10.0)), 200.0)));
	}

	unsigned UBoat::GetMaxSpeed() const
	{
		return GetDiveSpeed() > GetSailSpeed() ? GetDiveSpeed() : GetSailSpeed();
	}
}