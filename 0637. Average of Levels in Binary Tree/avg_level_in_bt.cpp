// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
// Example 1:
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
// Note:
// The range of node's value is in the range of 32-bit signed integer.

#include "../tree_helper.hpp"
#include <vector>

void bfs(TreeNode *node, std::vector<double> &sums, std::vector<double> &counts, int level) {
  if (!node)
    return;

  if (level == counts.size()) {
    sums.push_back(0);
    counts.push_back(0);
  }

  sums[level] += node->val;
  counts[level]++;

  bfs(node->left, sums, counts, level + 1);
  bfs(node->right, sums, counts, level + 1);
}

// 與 102 Binary Tree Level Order 相同思路
// 利用兩個陣列 一個存某層累加 一個存某層個數
// 最後再相除為答案
std::vector<double> averageOfLevels(TreeNode *root) {
  std::vector<double> res, counts;

  bfs(root, res, counts, 0);

  for (int i = 0; i < res.size(); i++) {
    res[i] /= counts[i];
  }

  return res;
}