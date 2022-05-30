#include "CircleLawn.h"
#include <cmath>

namespace lab5
{
	CircleLawn::CircleLawn(unsigned radius)
		: Lawn(radius, radius)
	{
	}

	unsigned CircleLawn::GetArea() const
	{
		return static_cast<unsigned>(round(3.14 * mHeight * mWidth));
	}
}
