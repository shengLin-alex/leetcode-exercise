// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:

//     2
//    / \
//   1   3

// Input: [2,1,3]
// Output: true
// Example 2:

//     5
//    / \
//   1   4
//      / \
//     3   6

// Input: [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

#include "../tree_helper.hpp"
#include <climits>
#include <vector>

// 解法 1 利用設定邊界來驗證值
// node->left->val 值必小於 node->val [mn, node->val]
// node->right->val 值必大於 node->val [node->val, mx]
bool dfs(TreeNode *node, long mn, long mx) {
  if (node == nullptr)
    return true;

  if (node->val <= mn || node->val >= mx)
    return false;

  return dfs(node->left, mn, node->val) && dfs(node->right, node->val, mx);
}

bool isValidBST(TreeNode *root) {
  return dfs(root, LONG_MIN, LONG_MAX);
}

// 解法二 由於題目定義該 bst left < root < right
// 因此 inorder 遍歷順序為有序序列
void inorder(TreeNode *root, std::vector<int> &vals) {
  if (!root)
    return;

  inorder(root->left, vals);
  vals.push_back(root->val);
  inorder(root->right, vals);
}

// 遍歷後檢查是否有序
bool isValidBST(TreeNode *root) {
  if (!root)
    return true;
  std::vector<int> vals;
  inorder(root, vals);

  for (int i = 0; i < vals.size() - 1; ++i) {
    if (vals[i] >= vals[i + 1])
      return false;
  }

  return true;
}