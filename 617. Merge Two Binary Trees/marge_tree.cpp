// Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are
// overlapped while the others are not.

// You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up
// as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

// Example 1:

// Input:
// 	Tree 1                     Tree 2
//           1                         2
//          / \                       / \                            
//         3   2                     1   3
//        /                           \   \                      
//       5                             4   7
// Output:
// Merged tree:
// 	     3
// 	    / \
// 	   4   5
// 	  / \   \ 
// 	 5   4   7

// Note: The merging process must start from the root nodes of both trees.

#include "../tree_helper.hpp"

// 寫法 1
// 把 t2 node 一顆一顆往t1 丟
TreeNode *mergeTree(TreeNode *t1, TreeNode *t2) {
  if (t2) // not null 表示該merge
  {
    TreeNode *n = new TreeNode(0);
    if (t1) // not null 表示該merge
    {
      n->val = t1->val + t2->val;
      n->left = mergeTree(t1->left, t2->left);
      n->right = mergeTree(t1->right, t2->right);
    } else // null 表示要複製t2的node過去
    {
      n->val = t2->val;
      n->right = t2->right;
      n->left = t2->left;
    }

    return n;
  } else // null 表示不用merge 直接原本
  {
    return t1;
  }
}

// 寫法 2
TreeNode *mergeTree(TreeNode *t1, TreeNode *t2) {
  if (t1 == nullptr)
    return t2;
  if (t2 == nullptr)
    return t1;

  t1->val += t2->val;
  t1->left = mergeTree(t1->left, t2->left);
  t1->right = mergeTree(t1->right, t2->right);

  return t1;
}

int main() {
  TreeNode *a = new TreeNode(1);
  TreeNode *b = new TreeNode(2);
  TreeNode *c = new TreeNode(3);
  TreeNode *aa = new TreeNode(1);
  TreeNode *bb = new TreeNode(2);
  TreeNode *cc = new TreeNode(3);

  a->left = b;
  b->left = c;

  aa->right = bb;
  bb->right = cc;

  auto res = mergeTree(a, aa);

  return 0;
}