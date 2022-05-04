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
		: mSize(other.GetLength())
	{
		mString = new char[mSize + 1];
		for (unsigned int i = 0; i < mSize; ++i)
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
		if (s == nullptr || s[0] == '\0')
			return;
		unsigned int i = 0;
		while (s[i] != '\0')
			i++;
		mSize += i;
		char* newString = new char[mSize + 1];
		i = 0;
		while (mString[i] != '\0')
		{
			newString[i] = mString[i];
			i++;
		}
		for (unsigned int j = 0; i < mSize; ++i)
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
		size_t otherLen = other.GetLength();
		size_t totalLen = mSize + otherLen;
		if (otherLen < 1)
			return *this;
		// alloc new mem to heap
		auto* newString = new char[totalLen + 1];
		for (unsigned int i = 0; i < mSize; ++i)
			newString[i] = mString[i];
		int j = 0;
		for (unsigned int i = mSize; i < totalLen; ++i)
			newString[i] = other.mString[j++];
		newString[totalLen] = '\0';
		MyString newStr(newString);
		delete[] newString;
		return newStr;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s[0] == '\0')
			return 0;
		for (unsigned int i = 0; i < mSize; ++i)
		{
			// when mString encounter s's first character jump else
			if (mString[i] == s[0])
			{
				int i2 = 0;
				for (unsigned int j = i; j <= mSize; j++)
				{
					if (s[i2] == '\0')
						return static_cast<int>(i);
					if (mString[j] != s[i2])
						break;
					i2++;
				}
			}
		}
		return -1;
	}


	// NNNEEDDD TO BE DONE
	int MyString::LastIndexOf(const char* s)
	{
		if (s[0] == '\0')
			return mSize;
		for (int i = static_cast<int>(mSize) - 1; i >= 0; --i)
		{
			if (mString[i] == s[0])
			{
				int i2 = 0;
				for (unsigned int j = i; j <= mSize; ++j)
				{
					if (s[i2] == '\0')
						return i;
					if (mString[j] != s[i2])
						break;
					i2++;
				}
			}
		}
		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		if (s[0] == '\0')
			return;
		int sLen = 0;
		int flag = 1;
		while (s[sLen] != '\0')
			sLen++;
		mSize += sLen;
		char* tempStore = new char[mSize + 1];
		int   idx1 = 0;
		int   idx2 = 0;
		for (unsigned int i = 0; i < mSize; ++i)
		{
			if (flag % 2 == 1 && mString[idx1] != '\0')
			{
				tempStore[i] = mString[idx1];
				idx1++;
			}
			else
			{
				if (s[idx2] != '\0')
				{
					tempStore[i] = s[idx2];
					idx2++;
				}
				else
				{
					i--;
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
		if (i >= mSize)
			return false;
		char* temporary = new char[mSize];
		mSize -= 1;
		for (unsigned int index = 0; index < i; ++index)
			temporary[index] = mString[index];
		for (unsigned int index = i; index < mSize; ++index)
			temporary[index] = mString[index + 1];
		temporary[mSize] = '\0';

		delete[] mString;
		mString = temporary;
		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength <= mSize)
			return;
		char*  temp = new char[totalLength + 1];
		unsigned int blank = totalLength - mSize;
		for (unsigned int i = 0; i < blank; ++i)
			temp[i] = ' ';
		int j = 0;
		for (unsigned int i = blank; i < totalLength; ++i)
			temp[i] = mString[j++];
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSize)
			return;
		char*        temp = new char[totalLength + 1];
		const unsigned int blank = totalLength - mSize;
		for (unsigned int i = 0; i < blank; ++i)
			temp[i] = c;
		int j = 0;
		for (unsigned int i = blank; i < totalLength; ++i)
			temp[i] = mString[j++];
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength <= mSize)
			return;
		char* temp = new char[totalLength + 1];
		for (unsigned int i = 0; i < mSize; ++i)
			temp[i] = mString[i];
		for (unsigned int i = mSize; i < totalLength; ++i)
			temp[i] = ' ';
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSize)
			return;
		char*        temp = new char[totalLength + 1];
		for (unsigned int i = 0; i < mSize; ++i)
			temp[i] = mString[i];
		for (unsigned int i = mSize; i < totalLength; ++i)
			temp[i] = c;
		temp[totalLength] = '\0';
		delete[] mString;
		mSize = totalLength;
		mString = temp;
	}

	void MyString::Reverse()
	{
		if (mSize < 1)
		{
			return ;
		}
		int lh = 0;
		int rh = static_cast<int>(mSize) - 1;
		while (lh < rh)
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
		if (rhs.GetLength() != GetLength())
			return false;
		for (unsigned int i = 0; i < mSize; ++i)
		{
			if (mString[i] != rhs.mString[i])
				return false;
		}
		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (rhs == *this)
			return *this;
		delete[] mString;
		if (rhs.mString[0] == '\0')
		{
			mSize = 0;
			mString[0] = '\0';
			return *this;
		}
		mSize = rhs.GetLength();
		mString = new char[mSize + 1];
		for (unsigned int i = 0; i < mSize; ++i)
			mString[i] = rhs.mString[i];
		mString[mSize] = '\0';
		return *this;
	}

	void MyString::ToLower()
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			if (mString[i] >= 'A' && mString[i] <= 'Z')
				mString[i] += 32;
		}
	}

	void MyString::ToUpper()
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			if (mString[i] >= 'a' && mString[i] <= 'z')
				mString[i] -= 32;
		}
	}
}
