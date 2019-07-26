// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example, given a 3-ary tree:

// https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png

// We should return its level order traversal:

// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]

// Note:

// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.

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

vector<vector<int>> levelOrder(Node *root) {
  vector<vector<int>> res;
  if (root == nullptr)
    return res;

  vector<Node *> tmp, tmp2;
  vector<int> nums;

  res.push_back({root->val});
  tmp.push_back(root);

  while (tmp.size() != 0) {
    tmp2.clear();
    nums.clear();

    for (auto n : tmp) {
      for (auto nn : n->children)
        tmp2.push_back(nn);
    }

    for (auto n : tmp2)
      nums.push_back(n->val);

    if (nums.empty())
      break;

    res.push_back(nums);
    tmp = tmp2;
  }

  return res;
}

int main() {
  Node *c = new Node(5, {});
  Node *d = new Node(0, {});
  Node *e = new Node(10, {c, d});
  Node *a = new Node(6, {});
  Node *f = new Node(3, {a});
  Node *b = new Node(1, {e, f});

  auto res = levelOrder(b);

  return 0;
}