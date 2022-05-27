#include "Airplane.h"
#include "Boat.h"
#include "DeusExMachina.h"

using namespace assignment2;

int main()
{
	Airplane a (4);
	Airplane a2(12);

	a.AddPassenger(new Person("jacob",12));
	a2 = a;
	
	a.RemovePassenger(0);

	DeusExMachina* d = DeusExMachina::GetInstance();

	// d->AddVehicle(a);
	// d->AddVehicle(a);

	d->RemoveVehicle(1);
}
