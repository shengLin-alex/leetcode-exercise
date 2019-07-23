// Given an n-ary tree, return the postorder traversal of its nodes' values.

// For example, given a 3-ary tree:

// Return its postorder traversal as: [5,6,3,2,4,1].

// Note:

// Recursive solution is trivial, could you do it iteratively?

#include <stack>
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

void helper(Node *root, vector<int> &con) {
    for (Node *child : root->children) {
        helper(child, con);
        con.push_back(child->val);
    }
}

// 遞迴
vector<int> postorder(Node *root) {
    vector<int> con;
    if (!root) {
        return con;
    }

    helper(root, con);
    con.push_back(root->val);
    return con;
}

// 迭代
vector<int> postorder(Node *root) {
    vector<int> con;
    if (!root) {
        return con;
    }

    stack<Node *> st{{root}};
    while (!st.empty()) {
        Node *t = st.top();
        st.pop();

        con.insert(con.begin(), t->val);
        for (auto child : t->children) {
            if (child)
                st.push(child);
        }
    }

    return con;
}