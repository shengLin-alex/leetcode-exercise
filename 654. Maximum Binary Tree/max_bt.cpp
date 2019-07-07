// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.

// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    /
//      2  0
//        \
//         1
// Note:
// The size of the given array will be in the range [1,1000].

#include "../tree_helper.hpp"
#include <vector>

using namespace std;

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return nullptr;
    }

    // 找出最大數字與其位置
    int max = 0;
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            index = i;
        }
    }

    // 拆兩半
    vector<int> leftPart(nums.begin(), nums.begin() + index);
    vector<int> rightPart(nums.begin() + index + 1, nums.end());

    TreeNode *root = new TreeNode(max);
    root->left = constructMaximumBinaryTree(leftPart);
    root->right = constructMaximumBinaryTree(rightPart);

    return root;
}