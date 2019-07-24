// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

#include "../tree_helper.hpp"
#include <vector>

TreeNode *helper(std::vector<int> &preorder, int pLeft, int pRight, std::vector<int> &inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight)
        return nullptr;

    TreeNode *cur = new TreeNode(preorder[pLeft]);

    int i = 0;
    for (i = iLeft; i < inorder.size(); i++) {
        if (inorder[i] == cur->val)
            break;
    }

    int leftLen = i - iLeft;
    cur->left = helper(preorder, pLeft + 1, pLeft + leftLen, inorder, iLeft, i - 1);
    cur->right = helper(preorder, pLeft + leftLen + 1, pRight, inorder, i + 1, iRight);

    return cur;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}