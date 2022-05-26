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
		const double speed = (500 * log((GetTotalWeight() + 150) / 150) + 30);
		return static_cast<unsigned>(round(speed));
	}

	unsigned UBoat::GetSailSpeed() const
	{
		const double speed = fmax((550 - GetTotalWeight() / 10), 200);
		return static_cast<unsigned>(round(speed));
	}

	unsigned UBoat::GetMaxSpeed() const
	{
		return GetDiveSpeed() > GetSailSpeed() ? GetDiveSpeed() : GetSailSpeed();
	}
}
