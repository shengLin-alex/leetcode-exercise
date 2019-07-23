// Given an n-ary tree, return the preorder traversal of its nodes' values.

// For example, given a 3-ary tree:

// https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png

// Return its preorder traversal as: [1,3,5,6,2,4].

// Note:

// Recursive solution is trivial, could you do it iteratively?

#include <vector>

using namespace std;

class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node *root) {
    vector<int> con;
    if (!root) {
        return con;
    }

    con.push_back(root->val);
    helper(root, con);

    return con;
}

void helper(Node *node, vector<int> &con) {
    for (Node *child : node->children) {
        con.push_back(child->val);
        helper(child, con);
    }
}