// Given a binary tree, flatten it to a linked list in-place.

// For example, given the following tree:

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

#include "../tree_helper.hpp"

void helper(TreeNode* node) {
    if (node == nullptr) return;
    if (node->left != nullptr) helper(node->left);
    if (node->right != nullptr) helper(node->right);

    TreeNode* tmp = node->right; // 暫存右邊
    node->right = node->left; // 斷開原本右邊接上左邊
    node->left = nullptr; // 左邊變成null
    while (node->right != nullptr) node = node->right; // 遍歷右邊(原本的左邊)直到null
    node->right = tmp; // 接上原本右邊
}

// 先試試看全部移到左邊然後再左右換位置
void flatten(TreeNode* root) {
    helper(root);
}

int main() {
    auto t = stringToTreeNode("[1,2,5,3,4,null,6]");
    flatten(t);

    return 0;
}