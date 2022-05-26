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
		return static_cast<unsigned>(round(fmax(-pow(GetTotalWeight() / 15, 3) + (2 * GetTotalWeight() + 400), 0)));
	}

	unsigned Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}
