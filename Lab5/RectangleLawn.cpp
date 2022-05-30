#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned width, unsigned height)
		: Lawn(width, height)
	{
	}

	unsigned RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned widthFence = mWidth * 4;
		unsigned heightFence = mHeight * 4;
		return (2 * (widthFence + heightFence));
	}

	unsigned RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR: return (2 * (mWidth + mHeight) * 6);
		case SPRUCE: return (2 * (mWidth + mHeight) * 7);
		default: Assert(false, "unknown type");
		}
	}

	unsigned RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}
}
