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

#include "../tree_helper.hpp"
#include <stack>
#include <vector>

// inorder 就是 dfs 然後優先走left

// recursive:
std::vector<int> res;
std::vector<int> inorderTraversal(TreeNode *root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }

    return res;
}

// 迭代
std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> result;
    std::stack<TreeNode *> tempStack;
    while (!tempStack.empty() || root != nullptr) {

        // 在 root != nullptr 時持續先往左邊 search
        if (root != nullptr) {
            tempStack.push(root);
            root = root->left;
        } else {
            // root 為 nullptr 後，開使依序從 stack 拿出 node
            // 由於 stack 的特性會優先取得最深的 left node
            root = tempStack.top();
            result.push_back((tempStack.top())->val);
            tempStack.pop();

            // 根據 inorder 將root 設為 right 往右繼續搜尋
            root = root->right;
        }
    }
    return result;
}