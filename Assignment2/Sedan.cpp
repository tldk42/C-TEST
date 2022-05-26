#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4),
		  mTrailer(nullptr),
		  mTrailerConnected(false)
	{
		Switch();
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailerConnected)
			return false;

		mTrailer = trailer;
		mTrailerConnected = true;
		Switch();
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (!mTrailerConnected)
			return false;

		delete mTrailer;
		mTrailer = nullptr;
		mTrailerConnected = false;
		Switch();
		return true;
	}

	unsigned Sedan::GetDriveSpeed() const
	{
		const unsigned trailerWeight = (mTrailerConnected) ? mTrailer->GetWeight() : 0;
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

	void Sedan::Switch()
	{
		if (mTrailerConnected)
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


