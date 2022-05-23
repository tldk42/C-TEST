#include <iomanip>
#include "Lab2.h"
#include <fstream>
#include <string>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		in.clear();
		std::vector<int> numberList;
		
		ScanNumber(in, numberList);
		if (!numberList.empty())
			PrintFormat(out, numberList);
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		in.clear();
		std::vector<float> numberList;
		
		ScanNumber(in, numberList);
		if (!numberList.empty())
			PrintFormat(out, numberList);
	}

	void ScanNumber(std::istream& in, std::vector<int>& numberList)
	{
		int         number;
		std::string trash;
		
		while (true)
		{
			in >> number;

			if (!in.fail())
			{
				numberList.push_back(number);
			}
			else
			{
				in.clear();
				in >> trash;
			}
			if (in.eof())
				break;
		}
	}

	void ScanNumber(std::istream& in, std::vector<float>& numberList)
	{
		float         number;
		std::string trash;
		
		while (true)
		{
			in >> number;

			if (!in.fail())
			{
				numberList.push_back(number);
			}
			else
			{
				in.clear();
				in >> trash;
			}
			if (in.eof())
				break;
		}
	}

	void PrintFormat(std::ostream& out, const std::vector<int> list)
	{

		out << std::setw(12) << "oct"
			<< std::setw(11) << "dec"
			<< std::setw(9) << "hex"
			<< std::endl
			<< std::setw(13) << std::setfill('-') << ' '
			<< std::setw(11) << ' '
			<< std::setw(8) << '-'
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

	void PrintText(std::fstream& file, std::ostream& out)
	{
		file.seekg(0);

		std::string line;
		while (true)
		{
			std::getline(file, line);
			out << line << std::endl;
			
			if (file.eof())
			{
				file.clear();
				break;
			}
		}
	}
}
