// Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R
// (inclusive).

// The binary search tree is guaranteed to have unique values.

// Example 1:

// Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
// Output: 32
// Example 2:

// Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
// Output: 23

// Note:

// The number of nodes in the tree is at most 10000.
// The final answer is guaranteed to be less than 2^31.

#include "tree_helper.hpp"
#include <iostream>

void helper(TreeNode *root, int l, int r, int &sum) {
    if (root == nullptr)
        return;

    if (l <= root->val && root->val <= r)
        sum += root->val;

    // 加左右判斷其實沒快多少
    helper(root->left, l, r, sum);
    helper(root->right, l, r, sum);
}

int rangeSumBST(TreeNode *root, int L, int R) {
    int sum = 0;
    helper(root, L, R, sum);

    return sum;
}

int main() {
    TreeNode *node = stringToTreeNode("[10,5,15,3,7,null,18]");

    int res = rangeSumBST(node, 7, 15);

    std::cout << res << std::endl;

    return 0;
}