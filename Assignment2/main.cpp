#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"

using namespace assignment2;
using namespace std;


int main()
{
	Boat* b = new Boat(2);
	b->AddPassenger(new Person("Jacob", 90));
	DeusExMachina* d = DeusExMachina::GetInstance();
	//d->AddVehicle(b);

	d->Travel();
	auto x = d->GetFurthestTravelled();
	auto k = x->GetDistance();
	return 0;
}



