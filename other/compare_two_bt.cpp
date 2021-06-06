#include "../tree_helper.hpp"

bool equals(TreeNode *root1, TreeNode *root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  } else if (root1 == nullptr && root2 != nullptr) {
    return false;
  } else if (root1 != nullptr && root2 == nullptr) {
    return false;
  } else {
    if (root1->val == root2->val && equals(root1->left, root2->left) && equals(root1->right, root2->right))
      return true;
    
    return false;
  }
}