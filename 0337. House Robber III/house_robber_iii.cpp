// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the
// "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that
// "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked
// houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

#include "../tree_helper.hpp"
#include <vector>

using namespace std;

// 用二維陣列來儲存
// [0] 不包含當前節點的最大值
// [1] 包含當前節點的最大值
vector<int> dfs(TreeNode *root) {
  if (root == nullptr)
    return vector<int>(2, 0);

  vector<int> left = dfs(root->left);
  vector<int> right = dfs(root->right);
  vector<int> res(2, 0);

  // 左子節點兩種狀況選大的 加上 右子節點兩種狀況選大的
  res[0] = max(left[0], left[1]) + max(right[0], right[1]);

  // 左右子節點不包含自己的最大值加上根節點的最大值
  res[1] = left[0] + right[0] + root->val;

  return res;
}

int rob(TreeNode *root) {
  auto res = dfs(root);
  return max(res[0], res[1]);
}