#include <fstream>
#include "Lab2.h"

#include <iostream>

using namespace std;

int main()
{
	//lab2::PrintIntegers(cin, cout);
	//lab2::PrintMaxFloat(cin, cout);
	fstream file;
	file.open("./result.txt", ios_base::in | ios_base::out);
	lab2::PrintText(file, cout);
	return 0;
}