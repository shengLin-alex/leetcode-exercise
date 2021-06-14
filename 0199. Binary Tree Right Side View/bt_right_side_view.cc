// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

// Example 1:
// https://assets.leetcode.com/uploads/2021/02/14/tree.jpg

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
// Example 2:

// Input: root = [1,null,3]
// Output: [1,3]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

#include "../tree_helper.hpp"
#include <vector>
#include <queue>

// bt level order 變化形
// 一樣用 queue，因為 FIFO，確保每一 level 最後放進去的 node 都是該層最後一個即可（取 queue.back()）
std::vector<int> rightSideView(TreeNode *root) {
  std::vector<int> res;
  if (!root)
    return res;

  std::queue<TreeNode *> qu;
  qu.push(root);

  while (!qu.empty()) {
    res.push_back(qu.back()->val);
    int size = qu.size();

     // 對 queue 內部目前 node 數量遍歷，取出下一層子 node
    for (int i = 0; i < size; i++) {
      TreeNode *parent = qu.front();
      qu.pop();

      // 由左至右放入 確保 queue 最後都會放進去最右邊的 node
      if (parent->left)
        qu.push(parent->left);

      if (parent->right)
        qu.push(parent->right);
    }
  }

  return res;
}