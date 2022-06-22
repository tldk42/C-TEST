#pragma once
#include <stack>

namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();

		/** \brief 시간복잡도 O(1) */
		void Push(T number);

		/** \brief 시간복잡도 O(1) */
		T Pop();

		/** \brief 스택에서 제일 위에 있는 숫자를 반환합니다. */
		T Peek();

		/** \brief	 * 시간복잡도 O(1)
		 *	스택에 있는 숫자들 중 가장 작은 숫자를 반환합니다.
		 *	스택이 비어있으면 템플릿형 T가 표현할 수 있는 가장 큰수를 반환합니다.
		 */
		T GetMin();

		/** \brief	 * 시간복잡도 O(1)
		 *	스택에 있는 숫자들 중 가장 큰 숫자를 반환합니다.
		 *	스택이 비어있으면 템플릿형 T가 표현할 수 있는 가장 작은수를 반환합니다.
		 */
		T GetMax();

		/** \brief 스택에 있는 수들의 평균을 반환합니다. */
		double GetAverage();

		/** \brief 스택에 있는 수들의 합을 반환합니다. */
		T GetSum();

		/** \brief 스택에 있는 수들의 분산을 반환합니다. */
		double GetVariance();

		/**	\brief 스택에 있는 수들의 표준 편차를 반환합니다. */
		double GetStandardDeviation();

		/** \brief 스택에 있는 요소들의 총개수를 반환합니다. */
		unsigned int GetCount();

	private:
		std::stack<T> mStack;
		std::stack<T> mMinStack;
		std::stack<T> mMaxStack;
		T             mSum;
		double        mSumPow;
	};

	template <typename T>
	SmartStack<T>::SmartStack()
		: mSum(0),
		  mSumPow(0)
	{
	}

	template <typename T>
	void SmartStack<T>::Push(T number)
	{
		mSum += number;
		mSumPow = sqrt(pow(mSumPow, 2) + pow(number, 2));
		if (mMinStack.empty())
		{
			mMinStack.push(number);
		}
		else
		{
			if (mMinStack.top() >= number)
			{
				mMinStack.push(number);
			}
		}
		if (mMaxStack.empty())
		{
			mMaxStack.push(number);
		}
		else
		{
			if (mMaxStack.top() <= number)
			{
				mMaxStack.push(number);
			}
		}
		mStack.push(number);
	}

	template <typename T>
	T SmartStack<T>::Pop()
	{
		if (mMinStack.top() == mStack.top())
		{
			mMinStack.pop();
		}
		if (mMaxStack.top() == mStack.top())
		{
			mMaxStack.pop();
		}
		T temp = mStack.top();
		mSum -= temp;
		mSumPow = sqrt(pow(mSumPow, 2) - pow(temp, 2));
		mStack.pop();
		return temp;
	}

	template <typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template <typename T>
	T SmartStack<T>::GetMin()
	{
		if (mStack.empty())
		{
			return std::numeric_limits<T>::max();
		}
		return mMinStack.top();
	}

	template <typename T>
	T SmartStack<T>::GetMax()
	{
		if (mStack.empty())
		{
			return std::numeric_limits<T>::lowest();
		}
		return mMaxStack.top();
	}

	template <typename T>
	double SmartStack<T>::GetAverage()
	{
		return (static_cast<double>(mSum) / static_cast<double>(mStack.size()));
	}

	template <typename T>
	T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template <typename T>
	double SmartStack<T>::GetVariance()
	{
		// Calculating Variance
		return (pow(mSumPow, 2) - GetAverage() * static_cast<double>(mSum)) / static_cast<double>(mStack.size());
	}

	template <typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template <typename T>
	unsigned SmartStack<T>::GetCount()
	{
		return mStack.size();
	}
}
