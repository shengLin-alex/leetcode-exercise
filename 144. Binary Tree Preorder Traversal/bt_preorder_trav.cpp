// Given a binary tree, return the preorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <vector>
#include <stack>
#include "tree_helper.hpp"

// 遞迴
// void trav(TreeNode* node, std::vector<int>& res) {
//     if (node == nullptr) return;

//     res.push_back(node->val);

//     trav(node->left, res);
//     trav(node->right, res);
// }

// std::vector<int> preorderTraversal(TreeNode *root) {
//     std::vector<int> res;
//     trav(root, res);
//     return res;
// }

std::vector<int> preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    std::vector<int> res;
    std::stack<TreeNode *> sk{{root}};

    while (!sk.empty())
    {
        TreeNode *node = sk.top();
        sk.pop();

        res.push_back(node->val);
        // 用 stack 所以先放 right 再放 left
        if (node->right != nullptr)
            sk.push(node->right);
        if (node->left != nullptr)
            sk.push(node->left);
    }

    return res;
}