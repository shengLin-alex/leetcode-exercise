// Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the
// most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary,
// which is 13.

// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

// Return the sum of these numbers.

// Example 1:

// https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png

// Input: [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

// Note:

// The number of nodes in the tree is between 1 and 1000.
// node.val is 0 or 1.
// The answer will not exceed 2^31 - 1.

#include "../tree_helper.hpp"
#include <cmath>
#include <vector>

void getPath(std::vector<std::vector<int>> &paths, std::vector<int> &path, TreeNode *node) {
  if (node == nullptr)
    return;

  path.push_back(node->val);

  if (node->left == nullptr && node->right == nullptr)
    paths.push_back(path);

  getPath(paths, path, node->left);
  getPath(paths, path, node->right);

  path.pop_back();
}

// 解法1 先取得所有路徑再算總和
int sumRootToLeaf(TreeNode *root) {
  std::vector<std::vector<int>> paths;
  std::vector<int> path;

  getPath(paths, path, root);
  int res = 0;

  for (auto p : paths) {
    int sum = 0, n = p.size();
    for (int i = n - 1; i >= 0; i--) {
      if (p[i] == 1)
        sum += pow(2, n - i - 1);
    }

    res += sum;
  }

  return res;
}

// 解法二 把取路徑跟計算合起來 非常的吊
int sumRootToLeaf2(TreeNode* root, int val = 0) {
  if (root == nullptr)
    return 0;

  // 每進去一層其實就是 2 增加一次方
  // 所以直接對 val 乘 2
  val = val * 2 + root->val;

  // root->left == root->right 其實就是表示該 root 已經為葉子回傳 val
  return root->left == root->right ? val : sumRootToLeaf2(root->left, val) + sumRootToLeaf2(root->right, val);
}

int main() {
  auto tree = stringToTreeNode("[1,0,1,0,1,0,1]");
  auto r = sumRootToLeaf(tree);

  return 0;
}