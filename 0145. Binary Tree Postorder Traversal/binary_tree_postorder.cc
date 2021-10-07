// Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

// Example 1:
// https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg

// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
// Example 4:
// https://assets.leetcode.com/uploads/2020/08/28/pre3.jpg

// Input: root = [1,2]
// Output: [2,1]
// Example 5:
//https://assets.leetcode.com/uploads/2020/08/28/pre2.jpg

// Input: root = [1,null,2]
// Output: [2,1]
 

// Constraints:

// The number of the nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

#include <vector>
#include "../tree_helper.hpp"

void dfs(std::vector<int> &res, TreeNode *root) {
  if (!root)
    return;

  dfs(res, root->left);
  dfs(res, root->right);
  res.push_back(root->val);
}

std::vector<int> postorderTraversal(TreeNode *root) {
  std::vector<int> res;
  dfs(res, root);

  return res;
}

int main() {
  auto root = stringToTreeNode("[1,null,2,3]");
  auto res = postorderTraversal(root);

  return 0;
}