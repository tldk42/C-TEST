#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4),
		  mTrailer(nullptr),
		  bTrailerConnected(false)
	{
		Toggle();
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (bTrailerConnected)
			return false;

		mTrailer = trailer;
		bTrailerConnected = true;
		Toggle();
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!bTrailerConnected)
			return false;

		delete mTrailer;
		mTrailer = nullptr;
		bTrailerConnected = false;
		Toggle();
		return true;
	}

	unsigned Sedan::GetDriveSpeed() const
	{
		const unsigned trailerWeight = (bTrailerConnected) ? mTrailer->GetWeight() : 0;
		const unsigned totalWeight = GetTotalWeight() + trailerWeight;

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

	void Sedan::Toggle()
	{
		if (bTrailerConnected)
		{
			mInterval = 7;
			mActive = 5;
		}
		else
		{
			mInterval = 6;
			mActive = 5;
		}
	}
}


