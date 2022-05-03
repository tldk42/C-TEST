#include "MyString.h"

/*
 * avoid using extra library
 * ex) cstring, string
 * programming with only while or for loop
 */

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		// loc var i is detecting parameter s's size
		int i = 0;

		while(s[i] != '\0') i++;
		mSize = i;
		mString = new char[mSize + 1];
		i = 0;
		while(s[i] != '\0')
		{
			mString[i] = s[i];
			i ++;
		}
		mString[i] = '\0';
	}

	MyString::MyString(const MyString& other)
		: mSize(other.GetLength())
	{
		mString = new char[mSize + 1];
		for(int i = 0; i < mSize; ++i) mString[i] = other.mString[i];
		mString[mSize] = '\0';
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		int i = 0;
		while(s[i] != '\0') i++;
		mSize += i;
		char* newString = new char[mSize + 1];
		i = 0;
		while(mString[i] != '\0')
		{
			newString[i] = mString[i];
			i++;
		}
		int j = 0;
		for(i; i < mSize; ++i)
		{
			newString[i] = s[j];
			j++;
		}
		newString[i] = '\0';
		delete[] mString;
		mString = newString;
	}

	// don't destroy
	MyString MyString::operator+(const MyString& other) const
	{
		size_t other_len = other.GetLength();
		size_t total_len = mSize + other_len;
		// alloc new mem to heap
		auto* newString = new char[total_len + 1];
		for(int i = 0; i < mSize; ++i) newString[i] = mString[i];
		int j = 0;
		for(int i = mSize; i < total_len; ++i) newString[i] = other.mString[j++];
		newString[total_len] = '\0';

		return {newString};
	}

	int MyString::IndexOf(const char* s)
	{
		for(int i = 0; i < mSize; ++i)
		{
			// when mString encounter s's first character jump else
			if(mString[i] == s[0])
			{
				int j = i;
				for(j; j <= mSize; j++)
				{
					if(*s == '\0') return i;
					if(mString[j] != *(s++)) break;
				}
			}
		}
		return -1;
	}


	// NNNEEDDD TO BE DONE
	int MyString::LastIndexOf(const char* s)
	{
		for(int i = mSize - 1; i >= 0; --i)
		{
			if(mString[i] == s[0])
			{
				int j = i;
				for(j; j <= mSize; ++j)
				{
					if(*s == '\0') return i;
					if(mString[j] != *(s++)) break;
				}
			}
		}
		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		// bool flow = false;
		// int i = 0;
		// while (s[i] != '\0')
		// 	i++;
		// const size_t totalLen = i + mSize;
		// mSize = totalLen;
		// auto *temporaryStore = new char[totalLen + 1];
		// for (i = 0; i < totalLen; ++i)
		// {
		// 	flow == true ? temporaryStore[i] = mString[i / 2] : temporaryStore[i] =  s[i / 2];
		// 	flow == true ? flow = false : flow = true;
		// }
		// temporaryStore[totalLen] = '\0';
		// // remove mem from heap
		// delete[] mString;
		// // pointing new String
		// mString = temporaryStore;

		int sLen = 0;
		int flag = 1;
		while(s[sLen] != '\0') sLen++;
		mSize += sLen;
		char* tempStore = new char[mSize + 1];
		int   idx1 = 0;
		int   idx2 = 0;
		for(int i = 0; i < mSize; ++i)
		{
			if(flag % 2 == 1 && mString[idx1] != '\0')
			{
				tempStore[i] = mString[idx1];
				idx1++;
			}
			else
			{
				if(s[idx2] != '\0')
				{
					tempStore[i] = s[idx2];
					idx2++;
				}
			}
			flag ++;
		}
		tempStore[mSize] = '\0';
		delete[] mString;
		mString = tempStore;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		if(i >= mSize) return false;
		char* temporary = new char[mSize];
		mSize -= 1;
		for(int index = 0; index < i; ++index) temporary[index] = mString[index];
		for(int index = i; index < mSize; ++index) temporary[index] = mString[index + 1];
		temporary[mSize] = '\0';

		delete[] mString;
		mString = temporary;
		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if(totalLength <= mSize) return;
		char*  temp = new char[totalLength + 1];
		size_t blank = totalLength - mSize;
		for(int i = 0; i < blank; ++i) temp[i] = ' ';
		int j = 0;
		for(int i = blank; i < totalLength; ++i) temp[i] = mString[j++];
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if(totalLength <= mSize) return;
		char*        temp = new char[totalLength + 1];
		const size_t blank = totalLength - mSize;
		for(int i = 0; i < blank; ++i) temp[i] = c;
		int j = 0;
		for(int i = blank; i < totalLength; ++i) temp[i] = mString[j++];
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if(totalLength <= mSize) return;
		char* temp = new char[totalLength + 1];
		for(int i = 0; i < mSize; ++i) temp[i] = mString[i];
		for(int i = mSize; i < totalLength; ++i) temp[i] = ' ';
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if(totalLength <= mSize) return;
		char*        temp = new char[totalLength + 1];
		const size_t blank = totalLength - mSize;
		for(int i = 0; i < mSize; ++i) temp[i] = mString[i];
		for(int i = mSize; i < totalLength; ++i) temp[i] = c;
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::Reverse()
	{
		int lh = 0;
		int rh = mSize - 1;
		while(lh < rh)
		{
			char temp = mString[lh];
			mString[lh] = mString[rh];
			mString[rh] = temp;
			lh ++;
			rh --;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if(rhs.GetLength() < 1) return false;

		for(int i = 0; i < mSize; ++i)
		{
			if(mString[i] != rhs.mString[i]) return false;
		}
		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		mSize = rhs.GetLength();
		char* newString = new char[mSize + 1];
		for(int i = 0; i < mSize; ++i) newString[i] = rhs.mString[i];
		newString[mSize] = '\0';
		return *this;
	}

	void MyString::ToLower()
	{
		for(int i = 0; i < mSize; ++i)
		{
			if(mString[i] >= 'A' && mString[i] <= 'Z') mString[i] += 32;
		}
	}

	void MyString::ToUpper()
	{
		for(int i = 0; i < mSize; ++i)
		{
			if(mString[i] >= 'a' && mString[i] <= 'z') mString[i] -= 32;
		}
	}
}
