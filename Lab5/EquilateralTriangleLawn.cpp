#include "EquilateralTriangleLawn.h"
#include <cmath>

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned size)
		: Lawn(size, size)
	{
	}

	unsigned EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		unsigned widthFence = mWidth * 4;
		return (3 * widthFence);
	}

	unsigned EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR: return (3 * mWidth * 6);
		case SPRUCE: return (3 * mWidth * 7);
		default: Assert(false, "unknown type");
		}
	}

	unsigned EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned>(round((sqrt(3) / 4) * mWidth * mWidth));
	}
}
