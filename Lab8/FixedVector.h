﻿#pragma once

namespace lab8
{
	template <typename T, size_t N>
	class FixedVector<T, N>
	{
	public:
		FixedVector();

		bool Add(const T& data);

		bool Remove(const T& data);

		const T& Get(unsigned int index) const;

		T& operator[](unsigned int index);

		int GetIndex(const T& data) const;

		size_t GetSize() const;

		size_t GetCapacity() const;

	private:
		size_t mSize;
		T      mArray[N];
	};

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& data)
	{
		if (mSize >= N)
		{
			return false;
		}

		mArray[mSize++] = data;

		return true;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& data)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == data)
			{
				for (size_t j = i; j < mSize - 1; ++j)
				{
					mArray[j] = mArray[j + 1];
				}
				mSize--;
				return true;
			}
		}
		return false;
	}

	template <typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned index) const
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& data) const
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == data)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}
