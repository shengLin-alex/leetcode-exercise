// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
 

// But the following [1,2,2,null,3,null,3] is not:

//     1
//    / \
//   2   2
//    \   \
//    3    3

// Note:
// Bonus points if you could solve it both recursively and iteratively.

#include <vector>
#include <iostream>
#include <algorithm>
#include "../tree_helper.hpp"

using namespace std;

void traversal(TreeNode *root, vector<pair<int,int>> &tmp, int label)
{
    if (root == nullptr) return;

    traversal(root->left, tmp, 1);
    tmp.push_back({root->val, label});
    traversal(root->right, tmp, 2);
}

bool isSymmetric(TreeNode *root)
{
    vector<pair<int,int>> tmp;
    traversal(root, tmp, 0);

    int st = 0, ed = tmp.size() - 1;
    while (st < ed)
    {
        if (tmp[st].first != tmp[ed].first) return false;
        if (tmp[st].second == tmp[ed].second) return false;
        st++;
        ed--;
    }

    return true;
}

int main(int argc, char** argv)
{
    auto t = stringToTreeNode("[1,2,2,3,4,4,3]");

    bool r = isSymmetric(t);

    cout << r << endl;

    return 0;
}