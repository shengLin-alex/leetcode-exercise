// Return the root node of a binary search tree that matches the given preorder traversal.

// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

// Example 1:

// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
// https://assets.leetcode.com/uploads/2019/03/06/1266.png
 

// Note: 

// 1 <= preorder.length <= 100
// The values of preorder are distinct.

#include "../tree_helper.hpp"
#include <vector>

class Solution {
public:
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        if (preorder.size() < 1) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(preorder[0]);
        
        std::vector<int> rv, lv;
        for (int child : preorder) {
            if (child == preorder[0]) {
                continue;
            }
            
            // bst 左小右大 分出兩半
            if (child > preorder[0]) {
                rv.push_back(child);
            } else {
                lv.push_back(child);
            }
        }
        
        // 遞迴往下組
        node->right = bstFromPreorder(rv);
        node->left = bstFromPreorder(lv);

        return node;
    }
};