#include <iomanip>
#include "Lab2.h"

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		std::vector<int> list1;
		int              number = 0;
		std::string      trash;
		std::string      num;
		while (true)
		{
			in >> number;
			
			if (!in.fail() && number >= 0)
			{
				list1.push_back(number);
			}
			else
			{
				in.clear();
				in >> trash;
			}
			if (in.eof())
				break;
		}
		if (!list1.empty())
			PrintFormat(out, list1);
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		std::vector<float> list1;
		float              number = 0;
		std::string        trash;
		std::string        num;
		while (true)
		{
			if (!in.fail() && number >= 0)
			{
				list1.push_back(number);
			}
			else
			{
				in.clear();
				in >> trash;
			}
			if (in.eof())
				break;
		}
		if (!list1.empty())
			PrintFormat(out, list1);
	}

	void PrintFormat(std::ostream& out, const std::vector<int> list)
	{

		out << std::setw(12) << "oct"
			<< std::setw(11) << "dec"
			<< std::setw(9) << "hex"
			<< std::endl
			<< std::setw(13) << std::setfill('-') << ' '
			<< std::setw(11) << ' '
			<< std::setw(9) << ' '
			<< std::endl;
		for (const auto value : list)
		{
			out << std::setfill(' ');
			out << std::setw(12) << std::oct << value
				<< std::setw(11) << std::dec << value
				<< std::setw(9) << std::hex << std::uppercase << value
				<< std::endl;
		}
	} 

	void PrintFormat(std::ostream& out, const std::vector<float> list)
	{
		float max = list.front();
		for (const auto value : list)
		{
			out << "     " << std::fixed << std::internal << std::setprecision(3)
				<< std :: setw(15) << std::showpos << value
				<< std::endl;
			if (max < value)
				max = value;
		}
		out << "max: " << std::fixed << std::internal << std::setprecision(3)
			<< std :: setw(15) << std::showpos << max
			<< std::endl;
	}
}
