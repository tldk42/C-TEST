#include <cassert>

#include "TimeSheet.h"
using namespace lab3;

int main()
{
	TimeSheet jacob("Jacob Lim", 90);

	/// add time to timeStamp
	/// discard time if < 1 or >10
	jacob.AddTime(3);
	jacob.AddTime(10);
	jacob.AddTime(11);

	/// return all time stamps 
	assert(jacob.GetTotalTime() == 13);

	/// return time stamp's average time
	assert(jacob.GetAverageTime() == 6.5f);

	/// return owner's name
	assert(jacob.GetName() == "Jacob Lim");

	assert(jacob.GetTimeEntry(1) == 10);
	
	
}

