#pragma once
#include "IDrivable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		// MAX((-(x/15)^3 + 2x + 400), 0)
		unsigned GetDriveSpeed() const override;
		unsigned GetMaxSpeed() const override;
	};
}