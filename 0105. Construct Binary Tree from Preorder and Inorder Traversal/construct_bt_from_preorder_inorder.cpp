// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

#include "../tree_helper.hpp"
#include <vector>

// 與 0106 剛好相反 preorder 在保證node value 不重複的前提下，開頭必定為 root
TreeNode *helper(std::vector<int> &preorder, int pLeft, int pRight, std::vector<int> &inorder, int iLeft, int iRight) {
  if (pLeft > pRight || iLeft > iRight)
    return nullptr;

  // 取出 root
  TreeNode *cur = new TreeNode(preorder[pLeft]);

  int i = 0;
  // 尋找 root 位置
  for (i = iLeft; i < inorder.size(); i++) {
    if (inorder[i] == cur->val)
      break;
  }

  int leftLen = i - iLeft;
  // 由於每次必定取開頭當root 所以 pLeft + 1
  cur->left = helper(preorder, pLeft + 1, pLeft + leftLen, inorder, iLeft, i - 1);
  
  cur->right = helper(preorder, pLeft + leftLen + 1, pRight, inorder, i + 1, iRight);

  return cur;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
  return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}