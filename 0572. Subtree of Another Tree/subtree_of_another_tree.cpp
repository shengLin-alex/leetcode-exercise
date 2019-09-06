// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a
// subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could
// also be considered as a subtree of itself.

// Example 1:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.
// Example 2:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.

#include "../tree_helper.hpp"

// 比較 s t 是否為相同值且子節點分布一樣樹
bool isSame(TreeNode *s, TreeNode *t) {
  if (!s && !t) // same null
    return true;
  
  if (!s || !t) // one is not null
    return false;

  if (s->val != t->val) // val not equal
    return false;

  return isSame(s->left, t->left) && isSame(s->right, t->right);
}

// 利用 isSame 來幫助檢查當前 s t 是否為同一棵樹(值相同節點分布相同)
bool isSubtree(TreeNode *s, TreeNode *t) {
  if (!s) // s is null
    return false;

  if (isSame(s, t))
    return true;

  // source 左子樹或右子數其中成立及成立
  return isSubtree(s->left, t) || isSubtree(s->right, t);
}