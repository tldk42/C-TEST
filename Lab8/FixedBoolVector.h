#pragma once
#include <cstdint>

namespace lab8
{
	static bool GetBit(const int32_t num, const int32_t i)
	{
		return ((num & (1 << i)) != 0);
	}

	static int32_t SetBit(const int32_t num, const int32_t i)
	{
		return num | (1 << i);
	}

	static int32_t ClearBit(const int32_t num, const int32_t i)
	{
		const int32_t mask = ~(1 << i);
		return num & mask;
	}

	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();

		bool Add(const bool& bData);

		bool Remove(const bool& bData);

		bool Get(unsigned int index) const;

		bool operator[](unsigned int index) const;

		int GetIndex(const bool& bData) const;

		size_t GetSize() const;

		size_t GetCapacity() const;
	private:
		size_t  mSize;
		int32_t mArray[(N / 32) + 1];
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0),
		  mArray{0}
	{
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(const bool& bData)
	{
		if (mSize >= N)
		{
			return false;
		}

		if (bData)
		{
			auto arraySize = mSize / 32;
			mArray[arraySize] = SetBit(mArray[arraySize], mSize);
		}
		mSize++;
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool& bData)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			// 만약 현재 bit가 data와 일치하는 bit
			if (GetBit(mArray[i / 32], i % 32) == bData)
			{
				//int32_t bitValue = ClearBit(mArray[i / 32], i % 32);
				for (size_t j = i; j < mSize - 1; ++j)
				{
					// 현재 bit의 다음 bit가 true일 때
					if (GetBit(mArray[(j + 1) / 32], (j + 1) % 32) == true)
					{
						// 현재 bit를 true로 바꿔준다.
						mArray[j / 32] = SetBit(mArray[j / 32], j % 32);
					}
					else
					{
						mArray[j / 32] = ClearBit(mArray[j / 32], j % 32);
					}
				}
				mSize--;
				mArray[mSize / 32] = ClearBit(mArray[mSize / 32], mSize % 32);
				return true;
			}
		}
		return false;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(unsigned index) const
	{
		return GetBit(mArray[index / 32], index % 32);
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](unsigned index) const
	{
		return GetBit(mArray[index / 32], index % 32);
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& bData) const
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (GetBit(mArray[i / 32], i % 32) == bData)
			{
				return i;
			}
		}
		return -1;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}
