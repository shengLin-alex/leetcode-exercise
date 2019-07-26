// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level
// by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

#include "tree_helper.hpp"
#include <queue>
#include <utility>
#include <vector>

// 同 0102 最後 reverse
std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
  if (root == nullptr)
    return {};

  std::queue<std::pair<TreeNode *, int>> qu;
  qu.push({root, 0});

  std::vector<std::vector<int>> res;
  while (!qu.empty()) {
    auto pr = qu.front();
    qu.pop();

    if (pr.second >= res.size())
      res.resize(pr.second + 1);

    res[pr.second].push_back(pr.first->val);

    if (pr.first->left != nullptr)
      qu.push({pr.first->left, pr.second + 1});
    if (pr.first->right != nullptr)
      qu.push({pr.first->right, pr.second + 1});
  }

  std::reverse(res.begin(), res.end());

  return res;
}

int main() {
  TreeNode *node = stringToTreeNode("[3,9,20,8,null,15,7]");
  auto res = levelOrderBottom(node);

  return 0;
}