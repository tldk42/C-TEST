#pragma once
#include "IFenceable.h"
#include "Lawn.h"


namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public :
		RectangleLawn(unsigned width, unsigned height);

		unsigned GetMinimumFencesCount() const override;
		unsigned GetFencePrice(eFenceType fenceType) const override;
		unsigned GetArea() const override;
	};
}
