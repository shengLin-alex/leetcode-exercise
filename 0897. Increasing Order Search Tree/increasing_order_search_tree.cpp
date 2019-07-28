// Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of
// the tree, and every node has no left child and only 1 right child.

// Example 1:
// Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

//        5
//       / \
//     3    6
//    / \    \
//   2   4    8
//  /        / \ 
// 1        7   9

// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

//  1
//   \
//    2
//     \
//      3
//       \
//        4
//         \
//          5
//           \
//            6
//             \
//              7
//               \
//                8
//                 \
//                  9

#include "../tree_helper.hpp"
#include <stack>

// 這個寫法有點太 tricky...
// TreeNode *dfs(TreeNode *root, TreeNode *tail) {
//   if (root == nullptr)
//     return tail;

//   TreeNode *res = dfs(root->left, root);
//   root->left = nullptr;
//   root->right = dfs(root->right, tail);

//   return res;
// }

// 眉角就是 reference of pointer
// 修改 pointer 的 reference 不會直接覆蓋該 pointer
void dfs(TreeNode *root, TreeNode *&tmp) {
  if (!root)
    return;

  dfs(root->left, tmp);

  tmp->right = root;
  root->left = nullptr;
  tmp = tmp->right;

  dfs(root->right, tmp);
}

TreeNode *increasingBST(TreeNode *root) {
  TreeNode *tmp = new TreeNode(-1);
  auto res = tmp;
  dfs(root, tmp);

  return res->right;
}

// TreeNode *increasingBST(TreeNode *root) {
//   std::stack<TreeNode *> st;
//   TreeNode *res = new TreeNode(-1), *tmp = res;

//   while (!st.empty() || root) {
//     if (root) {
//       st.push(root);
//       root = root->left;
//     } else {
//       root = st.top();
//       st.pop();

//       res->right = root;
//       root->left = nullptr;
//       res = res->right;

//       root = root->right;
//     }
//   }

//   return tmp->right;
// }

int main() {
  auto node = stringToTreeNode("[5,3,6,2,4,null,8,1,null,null,null,7,9]");
  auto res = increasingBST(node);

  return 0;
}