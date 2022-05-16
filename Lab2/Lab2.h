﻿#pragma once

#include <iostream>
#include <vector>
namespace lab2
{
	// in: 여기서 사용자 입력을 읽으세요. cin에서 읽는 게 아닙니다.
	// out: 여기에 출력을 쓰세요. cout에 쓰는 게 아닙니다.
	void PrintIntegers(std::istream& in, std::ostream& out);
	void PrintMaxFloat(std::istream& in, std::ostream& out);
	void ScanNumber(std::istream& in, std::vector<int>& numberList);
	void ScanNumber(std::istream& in, std::vector<float>& numberList);
	void PrintFormat(std::ostream& out, std::vector<int> list);
	void PrintFormat(std::ostream& out, std::vector<float> list);
}