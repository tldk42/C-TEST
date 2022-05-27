#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned Motorcycle::GetDriveSpeed() const
	{
		return static_cast<unsigned>(round(fmax(-pow(GetPassengerWeight() / 15.0, 3) + (2 * GetPassengerWeight() + 400), 0)));
	}

	unsigned Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}