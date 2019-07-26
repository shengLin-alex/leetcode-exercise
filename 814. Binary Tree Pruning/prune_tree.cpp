// We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

// Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

// (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

// Example 1:
// Input: [1,null,0,0,1]
// Output: [1,null,0,null,1]

// Explanation:
// Only the red nodes satisfy the property "every subtree not containing a 1".
// The diagram on the right represents the answer.
// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png

// Example 2:
// Input: [1,0,1,0,0,0,1]
// Output: [1,null,1,null,1]
// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png

// Example 3:
// Input: [1,1,0,1,1,0,1,0]
// Output: [1,1,0,1,1,null,1]
// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png

// Note:

// The binary tree will have at most 100 nodes.
// The value of each node will only be 0 or 1.

#include "tree_helper.hpp"

void trav_root(TreeNode *root, bool &has_one) {
  if (root == nullptr)
    return;

  if (root->val == 1) {
    has_one = true;
    return;
  }

  trav_root(root->left, has_one);
  trav_root(root->right, has_one);
}

TreeNode *trav_every(TreeNode *root) {
  if (root == nullptr)
    return nullptr;

  root->left = trav_every(root->left);
  root->right = trav_every(root->right);

  bool has_one = false;
  trav_root(root, has_one);

  if (!has_one) {
    return nullptr;
  } else {
    return root;
  }

  return root;
}

TreeNode *pruneTree(TreeNode *root) {
  trav_every(root);

  return root;
}

// 較好的寫法
TreeNode *pruneTree(TreeNode *root) {
  if (root == nullptr)
    return root;

  root->left = pruneTree(root->left);
  root->right = pruneTree(root->right);

  if (root->left || root->right || root->val)
    return root;

  return nullptr;
}

int main(int argc, char **argv) {
  TreeNode *tree = stringToTreeNode("[1,0,1,0,0,0,1]");

  auto res = pruneTree(tree);

  return 0;
}