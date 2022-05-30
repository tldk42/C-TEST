#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned size)
		: Lawn(size, size)
	{
	}

	unsigned SquareLawn::GetMinimumFencesCount() const
	{
		unsigned widthFence = mWidth * 4;
		return (4 * widthFence);
	}

	unsigned SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR: return (4 * mWidth * 6);
		case SPRUCE: return (4 * mWidth * 7);
		default: Assert(false, "unknown type");
		}
	}

	unsigned SquareLawn::GetArea() const
	{
		return mWidth * mWidth;
	}
}
