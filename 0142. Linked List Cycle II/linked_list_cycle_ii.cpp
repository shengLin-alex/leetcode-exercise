// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the
// linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

// Note: Do not modify the linked list.

// example see 141.

#include "linked_list_helper.hpp"
#include <vector>

using namespace std;

// 與上一題相同思路改成 return node
ListNode *helper(ListNode *head, vector<ListNode *> &v) {
    if (head == nullptr)
        return nullptr;

    if (find(v.begin(), v.end(), head) == v.end()) {
        v.push_back(head);
        return helper(head->next, v);
    } else {
        return head;
    }
}

ListNode *detectCycle(ListNode *head) {
    vector<ListNode *> v;
    return helper(head, v);
}