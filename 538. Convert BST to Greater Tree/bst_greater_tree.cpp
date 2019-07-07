// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

// Example:

// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13

// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13

#include <iostream>
#include "../tree_helper.hpp"

using namespace std;

// bst 所以先跑右邊，右邊的數字都比較大
void trav(TreeNode *node, int &sum)
{
    if (node == nullptr)
        return;

    trav(node->right, sum);

    int tmp = node->val;
    node->val += sum;
    sum += tmp; // 累加上去

    trav(node->left, sum);
}

TreeNode *convertBST(TreeNode *root)
{
    int sum = 0;
    trav(root, sum);

    return root;
}

int main()
{
    auto a = stringToTreeNode("[5,2,13,4,7]");
    auto res = convertBST(a);

    return 0;
}