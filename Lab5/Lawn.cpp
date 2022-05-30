#include "Lawn.h"
#include <cmath>

namespace lab5
{
	Lawn::Lawn(unsigned width, unsigned height)
		: mWidth(width),
		  mHeight(height)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		switch (grassType)
		{
		case BERMUDA: return static_cast<unsigned>(ceil(8 * GetArea()));
		case BAHIA: return static_cast<unsigned>(ceil(5 * GetArea()));
		case BENTGRASS: return static_cast<unsigned>(ceil(3 * GetArea()));
		case PERENNIAL_RYEGRASS: return static_cast<unsigned>(ceil(2.5 * GetArea()));
		case ST_AUGUSTINE: return static_cast<unsigned>(ceil(4.5 * GetArea()));
		default: Assert(false, "unknown type");
		}
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		const unsigned area = GetArea();
		if (area != 0)
		{
			const double neededRoll = area / 0.3;
			return static_cast<unsigned>(ceil(neededRoll));
		}
		return 0;
	}
}
