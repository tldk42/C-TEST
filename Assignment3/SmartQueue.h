#pragma once
#include <queue>

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();

		/** \brief 시간복잡도 O(1) */
		void Enqueue(T number);

		/** \brief 시간복잡도 O(1) */
		T Dequeue();

		/** \brief 큐에서 제일 위에 있는 숫자를 반환합니다. */
		T Peek();

		/** \brief	 * 시간복잡도 O(1)
		 *	큐에 있는 숫자들 중 가장 작은 숫자를 반환합니다.
		 *	큐이 비어있으면 템플릿형 T가 표현할 수 있는 가장 큰수를 반환합니다.
		 */
		T GetMin();

		/** \brief	 * 시간복잡도 O(1)
		 *	큐에 있는 숫자들 중 가장 큰 숫자를 반환합니다.
		 *	큐이 비어있으면 템플릿형 T가 표현할 수 있는 가장 작은수를 반환합니다.
		 */
		T GetMax();

		/** \brief 큐에 있는 수들의 평균을 반환합니다. */
		double GetAverage();

		/** \brief 큐에 있는 수들의 합을 반환합니다. */
		T GetSum();

		/** \brief 큐에 있는 수들의 분산을 반환합니다. */
		double GetVariance();

		/**	\brief 큐에 있는 수들의 표준 편차를 반환합니다. */
		double GetStandardDeviation();

		/** \brief 큐에 있는 요소들의 총개수를 반환합니다. */
		unsigned int GetCount();
	private:
		std::queue<T> mQueue;
		T             mSum;
		T             mSumPow;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0),
		  mSumPow(0)
	{
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mSum += number;
		mSumPow += static_cast<T>(pow(number, 2));

		mQueue.push(number);
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		T temp = mQueue.front();
		mSum -= temp;
		mSumPow -= static_cast<T>(pow(temp, 2));
		mQueue.pop();

		return temp;
	}

	template <typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template <typename T>
	T SmartQueue<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::max();
		}

		T    value = mQueue.front();
		auto copy = mQueue;
		copy.pop();
		for (unsigned i = 1; i < mQueue.size(); ++i)
		{
			value = value > copy.front() ? copy.front() : value;
			copy.pop();
		}
		return value;
	}

	template <typename T>
	T SmartQueue<T>::GetMax()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::lowest();
		}

		T    value = mQueue.front();
		auto copy = mQueue;
		copy.pop();
		for (unsigned i = 1; i < mQueue.size(); ++i)
		{
			value = value < copy.front() ? copy.front() : value;
			copy.pop();
		}
		return value;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage()
	{
		return (static_cast<double>(mSum) / static_cast<double>(mQueue.size()));
	}

	template <typename T>
	T SmartQueue<T>::GetSum()
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance()
	{
		return (static_cast<double>(mSumPow) - GetAverage() * static_cast<double>(mSum)) / static_cast<double>(mQueue.size());
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template <typename T>
	unsigned SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}
}
