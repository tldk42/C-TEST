#pragma once
#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn(unsigned size);

		unsigned GetMinimumFencesCount() const override;
		unsigned GetFencePrice(eFenceType fenceType) const override;
		unsigned GetArea() const override;
	};
}
