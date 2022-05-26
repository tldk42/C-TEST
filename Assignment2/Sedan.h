#pragma once
#include "IDrivable.h"
#include "Trailer.h"
#include "Vehicle.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		/**
		* If x <= 80, speed = 480 
		* If x > 80, speed = 458
		* If x > 160, speed = 400
		* If x > 260, speed = 380
		* If x > 350, speed = 300
		*/
		unsigned GetDriveSpeed() const override;
		unsigned GetMaxSpeed() const override;

	private:
		const Trailer* mTrailer;
		bool mTrailerConnected;

		void Switch();
	};
}
