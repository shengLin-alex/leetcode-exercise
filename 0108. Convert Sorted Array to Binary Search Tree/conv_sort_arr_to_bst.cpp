// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of
// every node never differ by more than 1.

// Example:

// Given the sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

#include "tree_helper.hpp"
#include <vector>

using namespace std;

// 因為已經排序
// 每次都取陣列正中間的元素當root
TreeNode *helper(vector<int> &nums, int start, int end) {
  if (start > end)
    return nullptr;

  int mid = start + (end - start) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = helper(nums, start, mid - 1);
  root->right = helper(nums, mid + 1, end);

  return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
  return helper(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> t = {-10, -3, 0, 5, 9, 11, 13};
  auto res = sortedArrayToBST(t);

  return 0;
}