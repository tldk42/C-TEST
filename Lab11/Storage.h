#pragma once
#include <memory>

namespace lab11
{
	template <typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage& other);
		Storage& operator=(const Storage& other);
		Storage(Storage&& other) noexcept;
		Storage& operator=(Storage&& other) noexcept;
		~Storage() = default;

		bool                        Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int                GetSize() const;
	private:
		std::unique_ptr<T[]> mDataBank;
		std::size_t          mLength;
	};

	template <typename T>
	Storage<T>::Storage(unsigned int length)
		: mDataBank(std::make_unique<T[]>(length)),
		  mLength(length)
	{
		for (std::size_t i = 0; i < mLength; ++i)
		{
			mDataBank[i] = {};
		}
	}

	template <typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mDataBank(std::make_unique<T[]>(length)),
		  mLength(length)
	{
		for (std::size_t i = 0; i < mLength; ++i)
		{
			mDataBank[i] = initialValue;
		}
	}

	template <typename T>
	Storage<T>::Storage(const Storage& other)
		: mDataBank(std::make_unique<T[]>(other.mLength)),
		  mLength(other.mLength)
	{
		for (std::size_t i = 0; i < mLength; ++i)
		{
			mDataBank[i] = other.mDataBank[i];
		}
	}

	template <typename T>
	Storage<T>& Storage<T>::operator=(const Storage& other)
	{
		if (this == &other)
			return *this;
		mDataBank.reset();
		mLength = other.mLength;
		mDataBank = std::make_unique<T[]>(mLength);
		for (std::size_t i = 0; i < mLength; ++i)
		{
			mDataBank[i] = other.mDataBank[i];
		}
		return *this;
	}

	template <typename T>
	Storage<T>::Storage(Storage&& other) noexcept
		: mDataBank(std::move(other.mDataBank)),
		  mLength(other.mLength)
	{
		other.mLength = 0;
	}

	template <typename T>
	Storage<T>& Storage<T>::operator=(Storage&& other) noexcept
	{
		if (this == &other)
			return *this;
		mDataBank = std::move(other.mDataBank);
		mLength = other.mLength;
		other.mLength = 0;
		return *this;
	}

	template <typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mLength)
			return false;
		mDataBank[index] = data;
		return true;
	}

	template <typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mDataBank);
	}

	template <typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}
