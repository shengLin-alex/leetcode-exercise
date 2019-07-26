// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

#include "../tree_helper.hpp"
#include <vector>

TreeNode *helper(std::vector<int> &inorder, int iLeft, int iRight, std::vector<int> &postorder, int pLeft, int pRight) {
  if (iLeft > iRight || pLeft > pRight)
    return nullptr;

  TreeNode *cur = new TreeNode(
      postorder[pRight]); // 由於題目限制輸入不會有重複node value，因此可確定 postorder 的最後一個值為 tree root

  int i = 0;
  for (i = iLeft; i < inorder.size(); i++) {
    if (inorder[i] == cur->val)
      break; // 藉由 root 以及 inorder 來拆分左右半邊
  }

  // build left，注意 pRight 更新為 root 至 iLeft 的距離加上原本的 pLeft 位置然後減一 => 區間 [pLeft, pLeft + leftLen)
  int leftLen = i - iLeft;
  cur->left = helper(inorder, iLeft, i - 1, postorder, pLeft, pLeft + leftLen - 1);
  // 因為每次都使用最後一個 postorder 值當 root 所以 pRight - 1 [pLeft + leftLen, pRight)
  cur->right = helper(inorder, i + 1, iRight, postorder, pLeft + leftLen, pRight - 1);

  return cur;
}

// 找出 root 以及左右區間再利用遞迴建構左右子樹
TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
  return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}