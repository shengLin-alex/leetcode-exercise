// Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to
// the sum of the values of the original tree that are greater than or equal to node.val.

// As a reminder, a binary search tree is a tree that satisfies these constraints:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:
// https://assets.leetcode.com/uploads/2019/05/02/tree.png

// Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

// Note:

// The number of nodes in the tree is between 1 and 100.
// Each node will have value between 0 and 100.
// The given tree is a binary search tree.

#include "../tree_helper.hpp"

class Solution {
  public:
    TreeNode *bstToGst(TreeNode *root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }

    void helper(TreeNode *node, int &sum) {
        if (!node) {
            return;
        }

        // bst 左小右大 往右走取比自己大的數累加
        helper(node->right, sum);
        node->val += sum;
        sum = node->val;

        helper(node->left, sum);
    }
};