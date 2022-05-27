#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4),
		  mTrailer(nullptr),
		  mbTrailerConnected(false)
	{
		toggle();
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mbTrailerConnected)
			return false;

		mTrailer = trailer;
		mbTrailerConnected = true;
		toggle();
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!mbTrailerConnected)
			return false;

		delete mTrailer;
		mTrailer = nullptr;
		mbTrailerConnected = false;
		toggle();
		return true;
	}

	unsigned Sedan::GetDriveSpeed() const
	{
		const unsigned trailerWeight = (mbTrailerConnected) ? mTrailer->GetWeight() : 0;
		const unsigned totalWeight = GetPassengerWeight() + trailerWeight;

		if (totalWeight <= 80)
		{
			return 480;
		}
		if (totalWeight <= 160)
		{
			return 458;
		}
		if (totalWeight <= 260)
		{
			return 400;
		}
		if (totalWeight <= 350)
		{
			return 380;
		}
		return 300;
	}

	unsigned Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	void Sedan::toggle()
	{
		if (mbTrailerConnected)
		{
		
		}
		else
		{
		
		}
	}
}