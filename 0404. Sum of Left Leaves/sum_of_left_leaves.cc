// Given the root of a binary tree, return the sum of all left leaves.

// Example 1:
// https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg

// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:

// Input: root = [1]
// Output: 0

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000

#include "../tree_helper.hpp"

void bfs(TreeNode *node, int &sum, bool isLeft) {
  if (!node)
    return;

  if (!node->left && !node->right && isLeft)
    sum += node->val;

  bfs(node->left, sum, true);
  bfs(node->right, sum, false);
}

int sumOfLeftLeaves(TreeNode *root) {
  int res = 0;
  bfs(root, res, false);

  return res;
}

int main() {
  auto tree = stringToTreeNode("[1,2,3,4,5]");
  auto res = sumOfLeftLeaves(tree);

  return 0;
}