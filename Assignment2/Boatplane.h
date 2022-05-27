#pragma once
#include "IFlyable.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		/** 150 * e ^ ((-x + 500) / 300) */
		unsigned GetFlySpeed() const override;

		/** MAX((800 - 1.7x), 20) */
		unsigned GetSailSpeed() const override;
		
		unsigned GetMaxSpeed() const override;
	};
}
