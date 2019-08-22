// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example:

// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.

#include "../tree_helper.hpp"
#include <climits>
#include <queue>

void helper(TreeNode *node, int &min, int depth) {
  if (!node)
    return;

  // 當確定為 leaf 時比較最淺深度
  if (!node->left && !node->right) {
    min = std::min(min, depth);
  }

  helper(node->left, min, depth + 1);
  helper(node->right, min, depth + 1);
}

// 解法1 dfs
// 但是實際上計算最淺應該用 bfs
int minDepth(TreeNode *root) {
  if (!root)
    return 0;

  int min = INT_MAX;
  helper(root, min, 1);

  return min;
}

// 解法2 bfs
int minDepth(TreeNode *root) {
  if (!root)
    return 0;

  std::queue<TreeNode*> qu{{root}};
  int depth = 0;
  while (!qu.empty()) {
    depth++;

    int len = qu.size();
    for (int j = 0; j < len; j++) {
      auto n = qu.front();
      qu.pop();
      if (n->left)
        qu.push(n->left);

      if (n->right)
        qu.push(n->right);
      
      if (!n->left && !n->right)
        return depth;
    }
  }

  return -1;
}

int main() {
  auto t = stringToTreeNode("[1,2]");
  auto r = minDepth(t);

  return 0;
}