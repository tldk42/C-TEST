#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned size)
		: RectangleLawn(size, size)
	{
	}

	unsigned SquareLawn::GetMinimumFencesCount() const
	{
		return RectangleLawn::GetMinimumFencesCount();
	}

	unsigned SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return RectangleLawn::GetFencePrice(fenceType);
	}

	unsigned SquareLawn::GetArea() const
	{
		return RectangleLawn::GetArea();
	}
}
