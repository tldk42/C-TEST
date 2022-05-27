#pragma once

#include "Boatplane.h"
#include "IDrivable.h"
#include "IFlyable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IDrivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		/** 4 * e^((-x + 400) / 70) */
		unsigned GetDriveSpeed() const override;
		
		/** 200 * e^((-x + 800) / 500) */
		unsigned GetFlySpeed() const override;
		
		unsigned GetMaxSpeed() const override;

		Boatplane operator+(Boat& boat);
	};
}
