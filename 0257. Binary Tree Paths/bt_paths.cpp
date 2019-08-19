// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

#include "../tree_helper.hpp"
#include <vector>

// 利用 bfs 遞迴將 node 值塞入陣列
void helper(std::vector<std::vector<int>> &res, std::vector<int> &sol, TreeNode *node) {
  if (node == nullptr)
    return;

  sol.push_back(node->val);

  // 檢查 node 左右皆無子樹時為 leaf
  if (node->left == nullptr && node->right == nullptr)
    res.push_back(sol);

  helper(res, sol, node->left);
  helper(res, sol, node->right);

  sol.pop_back(); // 回朔確保所有路徑都是 root-to-leaf
}

std::vector<std::string> binaryTreePaths(TreeNode *root) {
  std::vector<std::vector<int>> tmp;
  std::vector<int> sol;
  std::vector<std::string> res;

  helper(tmp, sol, root);

  // 重組為答案
  for (auto s : tmp) {
    std::string r = "";
    for (int i = 0; i < s.size(); i++) {
      if (i == 0) {
        r += std::to_string(s[i]);
      } else if (i > 0) {
        r += "->";
        r += std::to_string(s[i]);
      }
    }
    res.push_back(r);
  }

  return res;
}