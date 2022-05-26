#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
		mInterval = 6;
		mActive = 2;
	}

	UBoat::~UBoat()
	{
	}

	unsigned UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned>(round((500.f * log((GetTotalWeight() + 150) / 150) + 30)));
	}

	unsigned UBoat::GetSailSpeed() const
	{
		return static_cast<unsigned>(round(fmax((550.f - GetTotalWeight() / 10), 200)));
	}

	unsigned UBoat::GetMaxSpeed() const
	{
		return GetDiveSpeed() > GetSailSpeed() ? GetDiveSpeed() : GetSailSpeed();
	}
}
