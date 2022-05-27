#include "Airplane.h"
#include "Boat.h"

using namespace assignment2;

int main()
{
	Airplane a(10);
	a.AddPassenger(new Person("Jacob", 65));
	a.AddPassenger(new Person("acob", 65));
	a.AddPassenger(new Person("cob", 65));
	a.AddPassenger(new Person("Jb", 65));
	a.AddPassenger(new Person("ob", 65));
	Boat b(4);
	b.AddPassenger(new Person("sara", 54));
	b.AddPassenger(new Person("lucas", 54));

	Airplane a2(2);
	a2 = a;

	Boatplane bp = a + b;

	auto x = a.GetPassenger(4);
	x = bp.GetPassenger(6);
	x = bp.GetPassenger(3);

	x = a.GetPassenger(1);
	x = a.GetPassenger(4);
}
