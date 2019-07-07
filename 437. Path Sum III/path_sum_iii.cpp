// You are given a binary tree in which each node contains an integer value.

// Find the number of paths that sum to a given value.

// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

// Example:

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

#include <iostream>
#include "tree_helper.hpp"

// 經過node的解
void trav_root(TreeNode *node, int sum, int &res) {
    if (node == nullptr) return;

    sum -= node->val;
    if (sum == 0) res++;

    trav_root(node->left, sum, res);
    trav_root(node->right, sum, res);
}

// 經過所有node的最後解
void trav_every(TreeNode *root, int sum, int& ans) {
    if (root == nullptr) return;

    int res = 0;
    trav_root(root, sum, res);
    ans += res;

    trav_every(root->left, sum, ans);
    trav_every(root->right, sum, ans);
}

int pathSum(TreeNode *root, int sum) {    
    int ans = 0;
    trav_every(root, sum, ans);

    return ans;
}

int main() {
    auto root = stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");

    auto res = pathSum(root, 22);

    std::cout << res << std::endl;

    return 0;
}