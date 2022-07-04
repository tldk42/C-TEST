#include <cassert>
#include <iostream>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;

// void testFixedBoolVector()
// {
// 	FixedVector<bool, 34> fv;
// 	assert(!fv.Remove(false));
// 	assert(!fv.Remove(true));
// 	assert(fv.GetIndex(false) == -1);
// 	assert(fv.GetIndex(true) == -1);
//
// 	// 명세에 index는 항상 범위 내에 있다했고 빌드봇은 이런 테스트 하지 않음.
// 	assert(!fv[0]);
//
// 	// false 0~31 [0]
// 	for (size_t i = 0; i != 32; ++i)
// 	{
// 		fv.Add(false);
// 	}
//
// 	// false  0~31 [0]
// 	// true  32~33 [1]
// 	// GetSize() == 34
// 	fv.Add(true);
// 	fv.Add(true);
// 	assert(!fv.Get(31));
// 	assert(fv.Get(31) == fv[31]);
// 	assert(fv.Get(32));
// 	assert(fv.Get(32) == fv[32]);
// 	assert(fv.Get(33));
// 	assert(fv.Get(33) == fv[33]);
// 	assert(fv.GetSize() == 34);
// 	// false 0~30, true 31 [0]
// 	// true  32
//
// 	// GetSize() == 33
// 	fv.Remove(false);
// 	assert(fv.Get(31));
// 	assert(fv.Get(32));
// 	assert(fv.GetSize() == 33);
//
// 	FixedVector<bool, 64> fv2;
//
// 	// 0~31  [0] 00000000 11111111 00000000 11111111
// 	// 32~63 [1] 00000000 11111111 00000000 11111111
// 	for (size_t i = 0; i != 4; ++i)
// 	{
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(true));
// 		assert(fv2.Add(false));
// 		assert(fv2.Add(false));
// 		assert(fv2.Add(false));
// 		assert(fv2.Add(false));
// 		assert(fv2.Add(false));
// 		assert(fv2.Add(false));
// 		assert(fv2.Add(false));
// 		assert(fv2.Add(false));
// 	}
// 	assert(!fv2.Add(true));
//
// 	//  0~31 [0]   11111111 00000000 11111111 00000000
// 	// 32~55 [1] [00000000] 00000000 11111111 00000000
// 	//            ^^^^^^^^^
// 	//           [삭제된 요소]
// 	for (size_t i = 0; i != 8; ++i)
// 	{
// 		assert(fv2.Remove(true));
// 	}
//
// 	for (size_t i = 0; i != 56; ++i)
// 	{
// 		if (i < 8)
// 		{
// 			assert(!fv2.Get(i));
// 		}
// 		else if (i < 16)
// 		{
// 			assert(fv2.Get(i));
// 		}
// 		else if (i < 24)
// 		{
// 			assert(!fv2.Get(i));
// 		}
// 		else if (i < 32)
// 		{
// 			assert(fv2.Get(i));
// 		}
// 		else if (i < 40)
// 		{
// 			assert(!fv2.Get(i));
// 		}
// 		else if (i < 48)
// 		{
// 			assert(fv2.Get(i));
// 		}
// 		else if (i < 56)
// 		{
// 			assert(!fv2.Get(i));
// 		}
// 	}
//
// 	// 0~23 [0] [00000000] 11111111 11111111 11111111 
// 	for (size_t i = 0; i != 32; ++i)
// 	{
// 		assert(fv2.Remove(false));
// 	}
// 	assert(fv2.GetCapacity() == 64);
// 	assert(fv2.GetSize() == 24);
// 	assert(fv2.GetIndex(true) == 0);
// 	assert(fv2.GetIndex(false) == -1);
//
// 	for (size_t i = 0; i != 24; ++i)
// 	{
// 		assert(fv2.Remove(true));
// 	}
// 	assert(fv2.GetCapacity() == 64);
// 	assert(fv2.GetSize() == 0);
// 	assert(fv2.GetIndex(true) == -1);
//
// 	assert(!fv2.Remove(true));
// 	assert(!fv2.Remove(false));
//
// 	assert(fv2.GetIndex(true) == -1);
// 	assert(fv2.GetIndex(false) == -1);
// }
//
// void testFixedVector()
// {
// 	// int
// 	FixedVector<int, 5> intVector;
// 	assert(intVector.GetCapacity() == 5);
// 	assert(intVector.GetSize() == 0);
// 	assert(intVector.GetIndex(0) == -1);
// 	assert(!intVector.Remove(0));
// 	assert(!intVector[0]);
//
// 	for (auto i = 0; i != 5; ++i)
// 	{
// 		assert(intVector.Add(i));
// 		assert(intVector.GetCapacity() == 5);
// 		assert(intVector.GetSize() == i + 1);
// 		assert(intVector.Get(i) == i);
// 	}
// 	assert(intVector.Remove(1));
// 	assert(intVector.Get(4) == NULL);
//
// 	// int*
// 	FixedVector<int*, 5> fv;
// 	fv.Add(new int(3));
//
// 	FixedVector<int*, 5> fv2 = fv;
// 	assert(*fv2[0] == 3);
// 	assert(&fv[0] != &fv2[0]);
//
// 	fv2.Add(new int(5));
// 	assert(*fv2[1] == 5);
// 	//assert(*fv[1] == 0);
// 	assert(fv.GetSize() == 1);
//
// 	FixedVector<int*, 5> fv3;
// 	fv3.Add(new int(1));
// 	fv3.Add(new int(2));
// 	fv3.Add(new int(3));
//
// 	FixedVector<int*, 5> fv4;
// 	fv4 = fv3;
// 	assert(*fv3[0] == *fv4[0]);
// 	assert(&fv3[0] != &fv4[0]);
// }

int main()
{
	// testFixedBoolVector();
	// testFixedVector();
	FixedVector<bool, 5> s;
	s.Add(true);
}
