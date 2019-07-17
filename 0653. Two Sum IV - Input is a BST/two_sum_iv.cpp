// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True
 

// Example 2:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False

#include "../tree_helper.hpp"
#include <unordered_map>

// 利用 dfs 加上以往 Two Sum 系列的 hash map 檢查法
void dfs(TreeNode* root, int target, std::unordered_map<int, int>& map, bool& res) {
    if (root == nullptr) return;

    int ans = target - root->val;
    if (map.count(root->val) > 0) {
        res = true;
        return;
    }
    map[ans] = root->val;

    dfs(root->left, target, map, res);
    dfs(root->right, target, map, res);
}

bool findTarget(TreeNode* root, int k) {
    std::unordered_map<int, int> map;
    bool res = false;
    dfs(root, k, map, res);

    return res;
}

int main() {
    auto t = stringToTreeNode("[5,3,6,2,4,null,7]");
    auto res = findTarget(t, 28);

    return 0;
}