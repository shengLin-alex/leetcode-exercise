// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include "tree_helper.hpp"
#include <queue>
#include <utility>
#include <vector>

// 利用 bfs 加上 pair 紀錄某 node 在第幾階
std::vector<std::vector<int>> levelOrder(TreeNode *root) {
  if (root == nullptr)
    return {};

  std::queue<std::pair<TreeNode *, int>> qu;
  qu.push({root, 0}); // 初始將 root 設為 0層

  std::vector<std::vector<int>> res;
  while (!qu.empty()) {
    auto pr = qu.front();
    qu.pop();

    if (pr.second >= res.size())
      res.resize(pr.second + 1);

    // 層數即為res 的 元素 index
    res[pr.second].push_back(pr.first->val);

    // bfs 進入下一層時該層數也必須紀錄 + 1
    if (pr.first->left != nullptr)
      qu.push({pr.first->left, pr.second + 1});
    if (pr.first->right != nullptr)
      qu.push({pr.first->right, pr.second + 1});
  }

  return res;
}

// 遞迴法
void helper(TreeNode *node, int level, std::vector<std::vector<int>> &res) {
  if (!node)
    return;

  if (level == res.size())
    res.push_back({}); // 關鍵就是當層數不足時 push_back 空的層進入 res
  res[level].push_back(node->val); // 利用 level 幫助 access 到正確的層

  helper(node->left, level + 1, res);
  helper(node->right, level + 1, res);
}

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
  std::vector<std::vector<int>> res;
  helper(root, 0, res);

  return res;
}

int main() {
  TreeNode *node = stringToTreeNode("[3,9,20,8,null,15,7]");
  auto res = levelOrder(node);

  return 0;
}