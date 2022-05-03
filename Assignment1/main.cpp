#include <cstdio>

#include "MyString.h"

int main()
{
	const char* test = "A Yo 10bucks in my poc";
	
	assignment1::MyString testVariable("WhoAmI");
	assignment1::MyString testVariable2(testVariable);
	assignment1::MyString testVariable3 = testVariable + testVariable2;

	testVariable.Append(" I'm Jacob");
	testVariable.Append(" You?");

	auto s = testVariable.GetLength();
}