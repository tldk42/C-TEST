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
	DeusExMachina* d = DeusExMachina::GetInstance();
	auto x = d->GetFurthestTravelled();

	d->AddVehicle(new Motorcycle);
	d->AddVehicle(new Boat(4));
	d->AddVehicle(new UBoat);
	d->AddVehicle(new Sedan);

	 x = d->GetFurthestTravelled();
	x= d->GetFurthestTravelled();
	
	d->Travel();

	x = d->GetFurthestTravelled();

	d->Travel();
	x = d->GetFurthestTravelled();
	d->Travel();
	x = d->GetFurthestTravelled();
}



