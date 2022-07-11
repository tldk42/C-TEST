#pragma once
#include <memory>

namespace lab10
{
	template <typename T>
	class Node
	{
	public:
		Node();
		Node(std::shared_ptr<T> data);
		Node(const Node& other);
		Node& operator=(const Node& other);
		Node(Node&& other) noexcept;
		Node& operator=(Node&& other) noexcept;

		void SetNext(const std::shared_ptr<Node> next);
		void SetPrev(const std::shared_ptr<Node> prev);
		std::shared_ptr<Node> GetNext() const;
		std::shared_ptr<Node> GetPrev() const;

	private:
		T                     mData;
		std::shared_ptr<Node> mNext;
		std::weak_ptr<Node>   mPrevious;
	};

	template <typename T>
	Node<T>::Node()
	{
	}

	template <typename T>
	Node<T>::Node(std::shared_ptr<T> data)
		: mData(*data)
	{
	}

	template <typename T>
	Node<T>::Node(const Node& other)
		: mData(other.mData),
		  mNext(other.mNext),
		  mPrevious(other.mPrevious)
	{
	}

	template <typename T>
	Node<T>& Node<T>::operator=(const Node& other)
	{
		if (this == &other)
			return *this;
		mData = other.mData;
		mNext = other.mNext;
		mPrevious = other.mPrevious;
		return *this;
	}

	template <typename T>
	Node<T>::Node(Node&& other) noexcept
		: mData(std::move(other.mData)),
		  mNext(std::move(other.mNext)),
		  mPrevious(std::move(other.mPrevious))
	{
	}

	template <typename T>
	Node<T>& Node<T>::operator=(Node&& other) noexcept
	{
		if (this == &other)
			return *this;
		mData = std::move(other.mData);
		mNext = std::move(other.mNext);
		mPrevious = std::move(other.mPrevious);
		return *this;
	}

	template <typename T>
	void Node<T>::SetNext(const std::shared_ptr<Node> next)
	{
		if (next != nullptr)
		{
			//next->mPrevious = this;
			next->mNext = mNext;
			if (mNext != nullptr)
			{
				mNext->mPrevious = next;
			}
			mNext = next;
		}
	}
}
