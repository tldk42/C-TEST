#include "Lab6.h"
#include <climits>
#include <map>

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (const int iter : v)
		{
			sum += iter;
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.empty())
			return INT_MIN;
		
		int min = INT_MAX;
		for (int iter : v)
		{
			min = min > iter ? iter : min;
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.empty())
			return INT_MAX;
		
		int max = INT_MIN;
		for (int iter : v)
		{
			max = max < iter ? iter : max;
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.empty())
			return 0.f;

		float avg = static_cast<float>(Sum(v)) / static_cast<float>(v.size());

		return avg;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.empty())
			return 0;
		std::map<int, int> table;
		int maxOccurNumberCount = INT_MIN;
		int maxOccurNumber = INT_MIN;
		for (int iter : v)
		{
			table[iter]++;
		}
		for (auto iter : table)
		{
			maxOccurNumberCount = iter.second > maxOccurNumberCount ? iter.second : maxOccurNumberCount;
			if (iter.second == maxOccurNumberCount)
			{
				maxOccurNumber = iter.first;
			}
		}
		
		return maxOccurNumber;
	}

	void SortDescending(std::vector<int>& v)
	{
		if (v.empty())
			return ;
		SortRecursive(v, 0, v.size() - 1);
	}

	void SortRecursive(std::vector<int>& v, int lh, int rh)
	{
		if (lh >= rh)
			return ;

		const int pivotPos = Partition(v, lh, rh);

		SortRecursive(v, lh, pivotPos - 1);
		SortRecursive(v, pivotPos + 1 , rh);
	}
	
	int Partition(std::vector<int>& v, int lh, int rh)
	{
		int pivot = v[rh];
		int leftIndex = lh - 1;

		for (int i = lh;  i < rh; ++i)
		{
			if (pivot < v[i])
			{
				leftIndex++;
				const int temp = v[i];
				v[i] = v[leftIndex];
				v[leftIndex] = temp;
			}
		}
		leftIndex++;
		v[rh] = v[leftIndex];
		v[leftIndex] = pivot;
		pivot = leftIndex;

		return pivot;
	}
}
