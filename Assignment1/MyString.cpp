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
		
		while (s[i] != '\0')
			i++;
		mSize = i;
		mString = new char[mSize + 1];
		i = 0;
		while (s[i] != '\0')
		{
			mString[i] = s[i];
			i ++;
		}
		mString[i] = '\0';
	}

	MyString::MyString(const MyString& other)
		:mSize(other.GetLength())
	{
		mString = new char[mSize + 1];
		for (int i = 0; i < mSize; ++i)
			mString[i] = other.mString[i];
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
		while (s[i] != '\0')
			i++;
		mSize += i;
		char *newString = new char[mSize + 1];
		i = 0;
		while (mString[i] != '\0')
		{
			newString[i] = mString[i];
			i++;
		}
		int j = 0;
		for (i; i < mSize; ++i)
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
		auto *newString = new char[total_len + 1];
		for (int i = 0; i < mSize; ++i)
			newString[i] = mString[i];
		int j = 0;
		for (int i = mSize; i < total_len; ++i)
			newString[i] = other.mString[j++];
		newString[total_len] = '\0';
		
		return {newString};
	}

	int MyString::IndexOf(const char* s)
	{
		for (int i = 0; i < mSize; ++i)
		{
			// when mString encounter s's first character jump else
			if (mString[i] == s[0])
			{
				int j = i;
				for (j; j < mSize; ++j)
				{
					if (s[j] == '\0')
						return i;
					if (mString[j] != s[j])
						break;
				}
			}
		}
		return -1;
	}


	// NNNEEDDD TO BE DONE
	int MyString::LastIndexOf(const char* s)
	{
		return IndexOf(s);
	}

	void MyString::Interleave(const char* s)
	{
		const bool flow = false;
		int i = 0;
		while (s[i] != '\0')
			i++;
		const size_t totalLen = i + mSize;

		auto *temporaryStore = new char[totalLen + 1];
		for (i = 0; i < totalLen; ++i)
			flow == true ? temporaryStore[i] = mString[i % 2] : s[i % 2];
		// remove mem from heap
		delete[] mString;
		// pointing new String
		mString = temporaryStore;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		char *temporary = new char[mSize];
		
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}
}
