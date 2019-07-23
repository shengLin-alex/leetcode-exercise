// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along
// the parent-child connections. The path must contain at least one node and does not need to go through the root.

// Example 1:

// Input: [1,2,3]

//        1
//       / \
//      2   3

// Output: 6
// Example 2:

// Input: [-10,9,20,null,null,15,7]

//    -10
//    / \
//   9  20
//     /  \
//    15   7

// Output: 42

#include "tree_helper.hpp"
#include <climits>

// 此題重點技巧：利用回朔來取回朔至上一層node的較大值，但是利用 &res 取真正答案最大值(左加右加自己)
int dfs(TreeNode *node, int &res) {
    if (node == nullptr)
        return 0;

    int left = std::max(dfs(node->left, res), 0);   // 不取負
    int right = std::max(dfs(node->right, res), 0); // 同上
    res = std::max(res, left + right + node->val); // 左加右在加上 root val等於該 root 值，與前面的res比較取大的

    return std::max(left, right) + node->val; // 針對回朔至上一層的node, 左右取較大的加上自己的值
}

int maxPathSum(TreeNode *root) {
    int res = INT_MIN;
    dfs(root, res);

    return res;
}

int main() {
    auto t = stringToTreeNode("[1,-2,3]");
    auto r = maxPathSum(t);

    return 0;
}