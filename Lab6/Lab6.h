#pragma once

#include <vector>

namespace lab6
{
	/** Sum() 함수는 벡터의 모든 정수 요소들을 더한 값을 반환해야 합니다.
	 *만일 벡터가 비어 있다면 0을 반환합니다. */
	int Sum(const std::vector<int>& v);

	/** Min() 함수는 벡터의 정수 요소들 중 가장 작은 값을 반환해야 합니다.
	 * 예를 들어, 벡터의 요소가 { 3, 2, 1, 6, 8 }인 경우 최솟값인 1을 반환해야 합니다.
	 * 만약에 벡터가 비어 있다면 32비트 정수형이 표현할 수 있는 가장 큰 값을 반환합니다. */
	int Min(const std::vector<int>& v);

	/** Max() 함수는 벡터의 정수 요소들 중 가장 큰 값을 반환해야 합니다.
	 * 예를 들어, 벡터의 요소가 { 1, 3, 2, 4, 5 }인 경우 최댓값인 5를 반환해야 합니다.
	 * 만약에 벡터가 비어 있다면 32비트 정수형이 표현할 수 있는 가장 작은 값을 반환합니다. */
	int Max(const std::vector<int>& v);

	/** Average() 함수는 벡터의 정수 요소들의 평균값을 반환해야 합니다.
	 * 예를 들어, 벡터의 요소가 { 1, 2, 3, 5 }인 경우 평균으로 2.75f를 반환해야 합니다. */
	float Average(const std::vector<int>& v);

	/** NumberWithMaxOccurrence() 함수는 벡터 안에 있는 정수 중 어떤 정수가 가장 자주 등장하는지 알아 냅니다.
	 * 예를 들어, 벡터의 요소가 { 1, 3, 3, 5, 7, 3, -10 }인 경우 3을 반환해야 합니다.
	 * 만약에 가장 자주 등장하는 숫자가 둘 이상이라면, 그 숫자들 중 아무거나 반환하세요.
	 * 예를 들면, { 1, 1, 3, 3, 2, 6, -1 }인 경우 1 또는 3을 반환할 수 있습니다.
	 * 만약에 벡터가 비어 있다면 0을 반환합니다. */
	int NumberWithMaxOccurrence(const std::vector<int>& v);

	/** 벡터의 요소들을 내림차순으로 정렬합니다. */
	void SortDescending(std::vector<int>& v);

	void SortRecursive(std::vector<int>& v, int lh, int rh);
	
	int Partition(std::vector<int>& v, int lh, int rh);
}