// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

// Example 1:
// https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg

// Input: p = [1,2,3], q = [1,2,3]
// Output: true
// Example 2:
// https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg

// Input: p = [1,2], q = [1,null,2]
// Output: false
// Example 3:
// https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg

// Input: p = [1,2,1], q = [1,1,2]
// Output: false
 

// Constraints:

// The number of nodes in both trees is in the range [0, 100].
// -104 <= Node.val <= 104

#include "../tree_helper.hpp"

void bfs(TreeNode *a, TreeNode *b, bool &res) {
  if (!a && !b)
    return;

  if (a && !b || !a && b || a->val != b->val) {
    res = false;
    return;
  }

  bfs(a->left, b->left, res);
  bfs(a->right, b->right, res);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p && !q)
    return true;

  bool res = true;
  bfs(p, q, res);

  return res;
}

int main() {
  TreeNode *p = stringToTreeNode("[2,3,4]");
  TreeNode *q = stringToTreeNode("[2,3,4]");
  bool res = isSameTree(p, q);

  return 0;
}