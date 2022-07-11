#pragma once
#include <memory>
#include <queue>

namespace lab9
{
	template <typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool(ObjectPool&& other) = delete;
		ObjectPool& operator=(const ObjectPool& other) = delete;
		ObjectPool& operator=(ObjectPool&& other) = delete;

		~ObjectPool() = default;

		T*   Get();
		void Return(T*& object);

		size_t GetFreeObjectCount() const
		{
			return mPoolQueue.size();
		}

		size_t GetMaxFreeObjectCount() const
		{
			return mMaxPoolSize;
		}

	private:
		size_t                         mMaxPoolSize;
		std::queue<std::unique_ptr<T>> mPoolQueue;
	};

	template <typename T>
	ObjectPool<T>::ObjectPool(const size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize),
		  mPoolQueue()
	{
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mPoolQueue.empty())
		{
			return new T;
		}

		auto ptr = mPoolQueue.front().release();
		mPoolQueue.pop();
		return ptr;
	}

	template <typename T>
	void ObjectPool<T>::Return(T*& object)
	{
		std::unique_ptr<T> objPtr(object);
		//object = nullptr;
		if (mPoolQueue.size() >= mMaxPoolSize)
		{
			objPtr.reset();
			return;
		}
		mPoolQueue.push(std::move(objPtr));
	}
}
