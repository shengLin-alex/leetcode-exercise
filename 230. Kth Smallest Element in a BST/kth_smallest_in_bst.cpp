// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How
// would you optimize the kthSmallest routine?

#include "../tree_helper.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void traversal(TreeNode *root, vector<int> &tmp) {
  if (root == nullptr)
    return;

  traversal(root->left, tmp);
  tmp.push_back(root->val);
  traversal(root->right, tmp);
}

// traversal 然後再 sort
// 不知道為什麼感覺很爛但是OJ 評分 beat 80%
int kthSmallest(TreeNode *root, int k) {
  vector<int> tmp;
  traversal(root, tmp);
  sort(tmp.begin(), tmp.end());

  return tmp[k - 1];
}

int main() {
  auto t = stringToTreeNode("[5,3,6,2,4,null,null,1]");

  int res = kthSmallest(t, 3);

  return 0;
}