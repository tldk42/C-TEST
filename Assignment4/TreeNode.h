#pragma once

#include <memory>

namespace assignment4
{
	template <typename T>
	class TreeNode final
	{
	public:
		TreeNode(std::unique_ptr<T> data);
		TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data);
		TreeNode(TreeNode&& other) noexcept;
		TreeNode& operator=(TreeNode&& other) noexcept;

		bool IsLeaf() const
		{
			return (Left == nullptr && Right == nullptr);
		}

		std::unique_ptr<T>           Data;
		std::shared_ptr<TreeNode<T>> Left;
		std::shared_ptr<TreeNode<T>> Right;
		std::weak_ptr<TreeNode<T>>   Parent;
	};

	template <typename T>
	TreeNode<T>::TreeNode(std::unique_ptr<T> data)
		: Data(std::move(data))
	{
	}

	template <typename T>
	TreeNode<T>::TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data)
		: Data(std::move(data)),
		  Parent(parent)
	{
	}

	template <typename T>
	TreeNode<T>::TreeNode(TreeNode&& other) noexcept
		: Data(std::move(other.Data)),
		  Left(std::move(other.Left)),
		  Right(std::move(other.Right)),
		  Parent(std::move(other.Parent))
	{
	}

	template <typename T>
	TreeNode<T>& TreeNode<T>::operator=(TreeNode&& other) noexcept
	{
		if (this == &other)
			return *this;
		Data = std::move(other.Data);
		Left = std::move(other.Left);
		Right = std::move(other.Right);
		Parent = std::move(other.Parent);
		return *this;
	}
}
