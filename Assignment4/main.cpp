#include "TreeNode.h"

using namespace assignment4;

int main()
{
	TreeNode<int> n(std::make_unique<int>(2));

	std::shared_ptr<TreeNode<int>> parent = std::make_shared<TreeNode<int>>(std::make_unique<int>(5));
	TreeNode<int> n2(parent, std::make_unique<int>(2));
}