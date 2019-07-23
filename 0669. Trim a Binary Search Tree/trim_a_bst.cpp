// Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements
// lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of
// the trimmed binary search tree.

// Example 1:
// Input:
//     1
//    / \
//   0   2

//   L = 1
//   R = 2

// Output:
//     1
//       \
//        2
// Example 2:
// Input:
//     3
//    / \
//   0   4
//    \
//     2
//    /
//   1

//   L = 1
//   R = 3

// Output:
//       3
//      /
//    2
//   /
//  1

#include "../tree_helper.hpp"

TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (root == nullptr)
        return nullptr;

    // 當前 root 的值大於右邊界，則return trimBST(left)，left 的值必定小於 root
    if (root->val > R)
        return trimBST(root->left, L, R);

    // 當前 root 的值小於左邊界，則return trimBST(right)，right 的值必定大於 root
    if (root->val < L)
        return trimBST(root->right, L, R);

    // 當前 root 的值符合範圍的時候
    root->left = trimBST(root->left, L, R);   // 對左邊遞迴
    root->right = trimBST(root->right, L, R); // 對右邊遞迴

    return root;
}