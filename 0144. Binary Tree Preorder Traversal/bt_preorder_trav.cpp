// Given a binary tree, return the preorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include "tree_helper.hpp"
#include <stack>
#include <vector>

// 遞迴，preorder 就是先取值在左邊遞迴右邊遞迴
// void trav(TreeNode* node, std::vector<int>& res) {
//     if (node == nullptr) return;

//     res.push_back(node->val);

//     trav(node->left, res);
//     trav(node->right, res);
// }

// std::vector<int> preorderTraversal(TreeNode *root) {
//     std::vector<int> res;
//     trav(root, res);
//     return res;
// }

// 迭代
std::vector<int> preorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return {};

  std::vector<int> res;
  std::stack<TreeNode *> sk{{root}};

  while (!sk.empty()) {
    TreeNode *node = sk.top();
    sk.pop();

    res.push_back(node->val);

    // 由於使用 stack 後進先出所以先放 right 再放 left
    if (node->right != nullptr)
      sk.push(node->right);
    if (node->left != nullptr)
      sk.push(node->left);
  }

  return res;
}