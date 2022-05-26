#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
		mInterval = 6;
		mActive = 5;
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned Motorcycle::GetDriveSpeed() const
	{
		const double speed = fmax(-pow(GetTotalWeight() / 15, 3) + (2 * GetTotalWeight() + 400), 0);
		return static_cast<unsigned>(round(speed));
	}

	unsigned Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}
