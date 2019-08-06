// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as
// the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

// https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png

// Example 1:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
// Example 2:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA
// definition.

// Note:

// All of the nodes' values will be unique.
// p and q are different and both values will exist in the BST.

#include "../tree_helper.hpp"
#include <stack>

// 根據 binary search tree 之定義與題意
// 所求之解必定為尋訪 tree 時最先遇到之值位於 p q 之間之節點
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == nullptr)
    return nullptr;

  int left = p->val < q->val ? p->val : q->val;
  int right = p->val < q->val ? q->val : p->val;
  std::stack<TreeNode *> st{{root}};

  // 利用 stack 進行 bfs
  while (!st.empty()) {
    auto node = st.top();
    st.pop();

    // 當前尋訪到的節點值介於 [left,right] (閉區間)
    if (left <= node->val && node->val <= right) {
      return node;
    }

    if (node->right)
      st.push(node->right);
    if (node->left)
      st.push(node->left);
  }

  return nullptr;
}