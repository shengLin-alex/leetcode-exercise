// Given a binary tree, return the inorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <vector>
#include <stack>
#include "../tree_helper.hpp"

// recursive:
// vector<int> res;
// vector<int> inorderTraversal(TreeNode* root) {
//     if (root != nullptr) {
//         inorderTraversal(root->left);
//         res.push_back(root->val);
//         inorderTraversal(root->right);
//     }
        
//     return res;
// }

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> tempStack;
    while (!tempStack.empty() || root != nullptr) {
        if (root != nullptr) {
            tempStack.push(root);
            root = root->left;
        }
        else {
            root = tempStack.top();
            result.push_back((tempStack.top())->val);
            tempStack.pop();
            root = root->right;
        }
    }
    return result;
}