﻿#pragma once
#include <queue>
#include <stack>

namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);

		void Enqueue(T number);

		T Peek();

		T Dequeue();

		T GetMax();

		T GetMin();

		double GetAverage();

		T GetSum();

		unsigned GetCount();

		unsigned GetStackCount();


	private:
		unsigned                  mMaxStackSize;
		std::queue<std::stack<T>> mQueue;
		T                         mSum;
		unsigned                  mTCount;
	};

	template <typename T>
	QueueStack<T>::QueueStack(unsigned maxStackSize)
		: mMaxStackSize(maxStackSize),
		  mSum(0),
		  mTCount(0)
	{
	}

	template <typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		mSum += number;
		mTCount++;
		if (!mQueue.empty() && mQueue.back().size() < mMaxStackSize)
		{
			mQueue.back().push(number);
		}
		else
		{
			std::stack<T> temp;
			temp.push(number);
			mQueue.push(temp);
		}
	}

	template <typename T>
	T QueueStack<T>::Peek()
	{
		std::stack<T> frontStack = mQueue.front();
		return frontStack.top();
	}

	template <typename T>
	T QueueStack<T>::Dequeue()
	{
		T value = Peek();

		mSum -= value;
		mQueue.front().pop();
		mTCount--;

		if (mQueue.front().empty())
		{
			mQueue.pop();
		}
		return value;
	}

	template <typename T>
	T QueueStack<T>::GetMax()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::lowest();
		}

		T    value = std::numeric_limits<T>::lowest();
		auto copy = mQueue;

		for (unsigned i = 0; i < mQueue.size(); ++i)
		{
			unsigned stackSize = copy.front().size();
			for (unsigned j = 0; j < stackSize; ++j)
			{
				value = value < copy.front().top() ? copy.front().top() : value;
				copy.front().pop();
			}
			copy.pop();
		}

		return value;
	}

	template <typename T>
	T QueueStack<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::max();
		}

		T    value = std::numeric_limits<T>::max();
		auto copy = mQueue;

		for (unsigned i = 0; i < mQueue.size(); ++i)
		{
			unsigned stackSize = copy.front().size();
			for (unsigned j = 0; j < stackSize; ++j)
			{
				value = value > copy.front().top() ? copy.front().top() : value;
				copy.front().pop();
			}
			copy.pop();
		}

		return value;
	}

	template <typename T>
	double QueueStack<T>::GetAverage()
	{
		return (static_cast<double>(mSum) / static_cast<double>(mTCount));
	}

	template <typename T>
	T QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template <typename T>
	unsigned QueueStack<T>::GetCount()
	{
		return mTCount;
	}

	template <typename T>
	unsigned QueueStack<T>::GetStackCount()
	{
		return mQueue.size();
	}
}
