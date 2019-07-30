// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

// Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one
// possible tree.

// Each node of each tree in the answer must have node.val = 0.

// You may return the final list of trees in any order.

// Example 1:

// Input: 7
// Output:
// [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Explanation:

// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png

// Note:

// 1 <= N <= 20

#include "../tree_helper.hpp"
#include <vector>

std::vector<TreeNode *> allPossibleFBT(int N) {
  if (N % 2 == 0)
    return {}; // 根據題目，N 勢必為奇數，否則答案為空
  if (N == 1)
    return {new TreeNode(0)};

  std::vector<TreeNode *> res;

  // 建立跟節點後剩下 N - 1 個節點
  // 由於左右子樹也均由奇數個節點產生因此 => p + q = N - 1, 且 p q 為奇數
  for (int i = 1; i < N; i += 2) {
    // 拆分出左右子樹組合
    std::vector<TreeNode *> left = allPossibleFBT(i), right = allPossibleFBT(N - 1 - i);

    // 產生根節點並且接上左右子樹
    for (auto l : left) {
      for (auto r : right) {
          auto cur = new TreeNode(0);
          cur->left = l;
          cur->right = r;
          res.push_back(cur);
      }
    }
  }

  return res;
}

// follow up，可以使用 hash map 進行重複計算排除