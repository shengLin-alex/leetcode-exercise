// Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value
// sequence.

// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png

// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

// Note:

// Both of the given trees will have between 1 and 100 nodes.

#include "../tree_helper.hpp"
#include <vector>

void dfs(TreeNode *root, std::vector<int> &seq) {
    if (!root)
        return;

    if (!root->left && !root->right)
        seq.push_back(root->val);

    dfs(root->left, seq);
    dfs(root->right, seq);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    std::vector<int> seq1 = {}, seq2 = {};
    dfs(root1, seq1);
    dfs(root2, seq2);

    if (seq1.size() != seq2.size())
        return false;

    for (int i = 0; i < seq1.size(); i++)
        if (seq1[i] != seq2[i])
            return false;

    return true;
}