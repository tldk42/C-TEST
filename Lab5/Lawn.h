#pragma once

#include "eGrassType.h"
#ifdef DEBUG
#define Assert(e) assert(e)
#else
#define Assert(e) __assume(e)
#endif

namespace lab5
{
	class Lawn
	{
	public:
		Lawn(unsigned width, unsigned height);
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	protected:
		unsigned mWidth;
		unsigned mHeight;
	};
}
