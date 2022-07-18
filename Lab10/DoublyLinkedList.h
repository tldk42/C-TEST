#pragma once

#include <memory>

namespace lab10
{
	template <typename T>
	class Node;

	template <typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int             GetLength() const;

	private:
		std::shared_ptr<Node<T>> mEntry;
		std::weak_ptr<Node<T>>   mTail;
		unsigned                 mLength;
	private:
		std::shared_ptr<Node<T>> searchData(const T& data) const;
	};

	template <typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mEntry(nullptr),
		  mTail(mEntry),
		  mLength(0)
	{
	}

	template <typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mEntry == nullptr)
		{
			mEntry = std::make_shared<Node<T>>(std::move(data));
			mTail = mEntry;
		}
		else
		{
			if (!mTail.expired())
			{
				auto tailNode = mTail.lock();
				tailNode->Next = std::make_shared<Node<T>>(std::move(data), tailNode);
				mTail = tailNode->Next;
			}
		}
		mLength++;
	}

	template <typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (mLength <= index)
		{
			Insert(std::move(data));
			return;
		}

		auto                     node = (*this)[index];
		std::shared_ptr<Node<T>> newNode;

		// if previous node not exist ,, -> entryNode
		if (node->Previous.expired())
		{
			newNode = std::make_shared<Node<T>>(std::move(data));
			newNode->Next = node;
			node->Previous = newNode;
			mEntry = newNode;
		}
		// if next node not exist ,, -> tailNode
		else if (node->Next == nullptr)
		{
			newNode = std::make_shared<Node<T>>(std::move(data), node);
			node->Next = newNode;
			mTail = newNode;
		}
		// default case ,,
		else
		{
			auto prevNode = node->Previous.lock();
			newNode = std::make_shared<Node<T>>(std::move(data), prevNode);
			prevNode->Next = newNode;
			node->Previous = newNode;
			newNode->Next = node;
		}
		mLength++;
	}


	template <typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		auto node = searchData(data);
		if (node == nullptr)
		{
			return false;
		}

		// if previous node not exist ,, -> entryNode
		if (node->Previous.expired())
		{
			mEntry = mEntry->Next;
		}
		// if next node not exist ,, -> tailNode
		else if (node->Next == nullptr)
		{
			mTail = mTail.lock()->Previous;
			(*this)[mLength - 2]->Next = nullptr;
		}
		// default case ,,
		else
		{
			auto prevNode = node->Previous.lock();
			prevNode->Next = node->Next;
			node->Next->Previous = prevNode;
		}
		--mLength;
		return true;
	}

	template <typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		if (searchData(data) == nullptr)
		{
			return false;
		}
		return true;
	}


	template <typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mLength)
		{
			return nullptr;
		}
		auto node = mEntry;
		for (unsigned i = 0; i < index; ++i)
		{
			node = node->Next;
		}
		return node;
	}

	template <typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}

	template <typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::searchData(const T& data) const
	{
		auto findNode = mEntry;
		while (findNode != nullptr)
		{
			if (*findNode->Data == data)
			{
				return findNode;
			}
			findNode = findNode->Next;
		}
		return nullptr;
	}
}
