#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		DeusExMachina(const DeusExMachina&) = delete;
		DeusExMachina& operator=(const DeusExMachina&) = delete;
		DeusExMachina(DeusExMachina&&) = delete;
		DeusExMachina& operator=(DeusExMachina&&) = delete;

		static DeusExMachina* GetInstance();
		void                  Travel() const;
		bool                  AddVehicle(Vehicle* vehicle);
		bool                  RemoveVehicle(unsigned int i);
		const Vehicle*        GetFurthestTravelled() const;

	private:
		DeusExMachina() = default;
		//~DeusExMachina() = default;
		unsigned  mSize = 0;
		Vehicle** mVehicles = nullptr;
	};
}
