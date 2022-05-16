#include "TimeSheet.h"
#include <math.h>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mName(name),
		  mTimeStamp(new int[maxEntries]),
		  mMaxEntry(maxEntries),
		  mCurrentDay(0)
	{
	}

	TimeSheet::TimeSheet(const TimeSheet& copy)
		: mName(copy.mName),
		  mTimeStamp(new int[copy.mMaxEntry]),
		  mMaxEntry(copy.mMaxEntry),
		  mCurrentDay(copy.mCurrentDay)
	{
		for (unsigned int i = 0; i < mCurrentDay; ++i)
			mTimeStamp[i] = copy.mTimeStamp[i];
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		if (rhs.mName == this->mName)
			return *this;
		delete[] mTimeStamp;
		mName = rhs.mName;
		mTimeStamp = new int[rhs.mMaxEntry];
		mMaxEntry = rhs.mMaxEntry;
		mCurrentDay = rhs.mCurrentDay;
		for (unsigned int i = 0; i < mCurrentDay; ++i)
			mTimeStamp[i] = rhs.mTimeStamp[i];
		return *this;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTimeStamp;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		// 최소 1시간 최대 10시간이 아닐경우 예외 처리
		if (timeInHours < 1 || timeInHours > 10)
			return ;

		// 근무일 수를 초과시 예외 처리
		if (mCurrentDay >= mMaxEntry)
			return;
		
		// timeStamp에 기록
		mTimeStamp[mCurrentDay++] = timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		// 유효하지 않은 근무일자를 조회할 시 예외처리
		if (index < 0 || index >= mCurrentDay)
			return -1;
		
		return mTimeStamp[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int totalTime = 0;
		
		for (unsigned int i = 0; i < mCurrentDay; ++i)
		{
			totalTime += mTimeStamp[i];	
		}
		return totalTime;
	}

	float TimeSheet::GetAverageTime() const
	{
		// 최소 근무일수 아닐시 예외처리
		if (mCurrentDay < 1)
			return 0.f;
		
		float totalTime = static_cast<float>(GetTotalTime());
		float averageTime = totalTime / static_cast<float>(mCurrentDay);
		
		return (averageTime);
	}

	float TimeSheet::GetStandardDeviation() const
	{
		// 예외 처리
		if (mCurrentDay < 1)
			return 0.0f;
		// 평균값
		float average = GetAverageTime();

		// 분산구하기
		float varResult = 0.f;
		for (unsigned int i = 0; i < mCurrentDay; ++i)
		{
			float var = static_cast<float>(mTimeStamp[i]) - average;
			varResult += (var * var);
		}
		varResult = varResult / static_cast<float>(mCurrentDay);
		return sqrtf(varResult);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
	
}
