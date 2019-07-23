// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

#include "tree_helper.hpp"
#include <vector>

void trav_root(TreeNode *node, int sum, std::vector<std::vector<int>> &res, std::vector<int> &tmp) {
    if (node == nullptr)
        return;

    tmp.push_back(node->val);

    sum -= node->val;

    // 檢查是否為一組解且為最後的葉節點
    if (sum == 0 && node->left == nullptr && node->right == nullptr)
        res.push_back(tmp);

    trav_root(node->left, sum, res, tmp);
    trav_root(node->right, sum, res, tmp);

    tmp.pop_back(); // call stack 回朔到上一層時要 pop 最後的值
}

std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;

    trav_root(root, sum, res, tmp);

    return res;
}

int main() {
    TreeNode *root = stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");

    auto res = pathSum(root, 22);

    return 0;
}