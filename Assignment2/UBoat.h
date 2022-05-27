#pragma once
#include "IDivable.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		~UBoat();

		// 500 * log((x + 150)/150) + 30
		unsigned GetDiveSpeed() const override;
		
		// MAX((550 - x/10), 200)
		unsigned GetSailSpeed() const override;
		
		unsigned GetMaxSpeed() const override;
	};
}