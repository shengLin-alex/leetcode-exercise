// Invert a binary tree.

// Example:

// Input:

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// Output:

//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
// Trivia:
// This problem was inspired by this original tweet by Max Howell:

// Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a
// whiteboard so f*** off.

#include "../tree_helper.hpp"

TreeNode *invertTree(TreeNode *root) {
  if (root == nullptr)
    return root;

  helper(root);
  return root;
}

void helper(TreeNode *node) {
  if (node == nullptr)
    return;

  std::swap(node->left, node->right);
  helper(node->left);
  helper(node->right);
}