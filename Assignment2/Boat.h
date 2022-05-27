#pragma once

#include "Boatplane.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();
		
		/** MAX((800 - 10x), 20) */
		unsigned GetSailSpeed() const override;
		
		unsigned GetMaxSpeed() const override;

		Boatplane operator+(Airplane& plane);
	};
}
