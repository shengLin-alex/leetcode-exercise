// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Note: A leaf is a node with no children.

// Example:

// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its depth = 3.

#include "../tree_helper.hpp"

// 利用 dfs 計算每一個節點左邊最深與右邊最深並將就深的深度回朔至前一層 call stack
int maxDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }

    int leftDepth = 1 + maxDepth(root->left);
    int rightDepth = 1 + maxDepth(root->right);

    return rightDepth > leftDepth ? rightDepth : leftDepth;
}