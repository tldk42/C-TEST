#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template <typename T>
	class TreeNode;

	template <typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree() = default;

		void                             Insert(std::unique_ptr<T> data);
		bool                             Search(const T& data);
		bool                             Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		void InsertRecursive(std::unique_ptr<T>& data, std::shared_ptr<TreeNode<T>>& node);
		bool SearchRecursive(const T& data, std::shared_ptr<TreeNode<T>>& node);
		bool DeleteRecursive(const T& data, std::shared_ptr<TreeNode<T>>& node);
		void SwapRecursive(std::shared_ptr<TreeNode<T>>& deleteThisNode, std::shared_ptr<TreeNode<T>>& switchThisNode);

		static std::vector<T>& TraverseInOrderRecursive(std::vector<T>& tracedVector, std::shared_ptr<TreeNode<T>> node);
		static std::vector<T>  TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot;
	};

	template <typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		InsertRecursive(data, mRoot);
	}

	template <typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		return SearchRecursive(data, mRoot);
	}

	template <typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return DeleteRecursive(data, mRoot);
	}

	template <typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template <typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> tracedVector;
		if (startNode == nullptr)
		{
			return tracedVector;
		}
		return TraverseInOrderRecursive(tracedVector, startNode);
	}

	template <typename T>
	void BinarySearchTree<T>::InsertRecursive(std::unique_ptr<T>& data, std::shared_ptr<TreeNode<T>>& node)
	{
		if (node == nullptr)
		{
			node = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}
		if (*node->Data < *data)
		{
			if (node->Right == nullptr)
			{
				node->Right = std::make_shared<TreeNode<T>>(std::move(data));
				node->Right->Parent = node;
				return;
			}
			return InsertRecursive(data, node->Right);
		}
		else
		{
			if (node->Left == nullptr)
			{
				node->Left = std::make_shared<TreeNode<T>>(std::move(data));
				node->Left->Parent = node;
				return;
			}
			return InsertRecursive(data, node->Left);
		}
	}

	template <typename T>
	bool BinarySearchTree<T>::SearchRecursive(const T& data, std::shared_ptr<TreeNode<T>>& node)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (*node->Data == data)
		{
			return true;
		}
		if (*node->Data < data)
		{
			return SearchRecursive(data, node->Right);
		}
		return SearchRecursive(data, node->Left);
	}

	template <typename T>
	bool BinarySearchTree<T>::DeleteRecursive(const T& data, std::shared_ptr<TreeNode<T>>& node)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (*node->Data == data)
		{
			if (node->IsLeaf())
			{
				node = nullptr;
			}
			else if (node->Left != nullptr)
			{
				SwapRecursive(node, node->Left);
			}
			else
			{
				SwapRecursive(node, node->Right);
			}
			return true;
		}
		if (*node->Data < data)
		{
			return DeleteRecursive(data, node->Right);
		}
		return DeleteRecursive(data, node->Left);
	}

	template <typename T>
	void BinarySearchTree<T>::SwapRecursive(std::shared_ptr<TreeNode<T>>& deleteThisNode, std::shared_ptr<TreeNode<T>>& switchThisNode)
	{
		if (*deleteThisNode->Data >= *switchThisNode->Data)
		{
			if (switchThisNode->Right == nullptr)
			{
				std::swap(deleteThisNode->Data, switchThisNode->Data);
				// general
				if (switchThisNode->Left != nullptr)
				{
					switchThisNode->Left->Parent = switchThisNode->Parent;
				}
				if (deleteThisNode->Left == switchThisNode)
				{
					deleteThisNode->Left = switchThisNode->Left;
				}
				else
				{
					switchThisNode->Parent.lock()->Right = switchThisNode->Left;
				}
				return;
			}
			return SwapRecursive(deleteThisNode, switchThisNode->Right);
		}
		else
		{
			if (switchThisNode->Left == nullptr)
			{
				std::swap(deleteThisNode->Data, switchThisNode->Data);
				if (switchThisNode->Right != nullptr)
				{
					switchThisNode->Right->Parent = switchThisNode->Parent;
				}
				if (deleteThisNode->Right == switchThisNode)
				{
					deleteThisNode->Right = switchThisNode->Right;
				}
				else
				{
					switchThisNode->Parent.lock()->Left = switchThisNode->Right;
				}
				return;
			}
			return SwapRecursive(deleteThisNode, switchThisNode->Left);
		}
	}

	template <typename T>
	std::vector<T>& BinarySearchTree<T>::TraverseInOrderRecursive(std::vector<T>& tracedVector, std::shared_ptr<TreeNode<T>> node)
	{
		if (node->Left != nullptr)
			TraverseInOrderRecursive(tracedVector, node->Left);
		tracedVector.push_back(*node->Data);
		if (node->Right != nullptr)
			TraverseInOrderRecursive(tracedVector, node->Right);
		return tracedVector;
	}
}
