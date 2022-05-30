#pragma once
#include "IFenceable.h"
#include "Lawn.h"
#include "RectangleLawn.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned size);

		unsigned GetMinimumFencesCount() const override;
		unsigned GetFencePrice(eFenceType fenceType) const override;
		unsigned GetArea() const override;
		
	};
}
