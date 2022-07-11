#pragma once
#include <memory>
#include <memory>

#include "Node.h"

namespace lab10
{
	template <typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();

		void Insert(std::unique_ptr<T> data, unsigned index = 0);

		bool Search(T) const;

		bool Delete(T) const;

		std::shared_ptr<Node<T>> operator[](uint32_t index) const;

		uint32_t GetLength() const;

	private:
		uint32_t mLength;
		std::shared_ptr<Node<T>> mRoot;
		std::weak_ptr<Node<T>> mCurrentNode;
	};


	template <typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mLength(0),
		  mRoot(nullptr),
		  mCurrentNode(mRoot)
	{
	}

	template <typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned index)
	{
		if (mLength == 0)
		{
			mRoot = std::make_shared<Node<T>>(std::move(data));
			mCurrentNode = mRoot;
		}
		else
		{
			if (!mCurrentNode.expired())
			{
				auto currentNode = mCurrentNode.lock();
				mCurrentNode = std::make_shared<Node<T>>(std::move(data));
				currentNode->SetNext(mCurrentNode.lock());
				currentNode.reset();
			}
		}
		mLength++;
	}


	template <typename T>
	bool DoublyLinkedList<T>::Search(T) const
	{
		return false;
	}

	template <typename T>
	bool DoublyLinkedList<T>::Delete(T) const
	{
		return false;
	}

	template <typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](uint32_t index) const
	{
		return std::make_shared<Node<T>>(0);
	}


	template <typename T>
	uint32_t DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}
