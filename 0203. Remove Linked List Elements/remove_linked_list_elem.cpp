// Remove all elements from a linked list of integers that have value val.

// Example:

// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

#include "../linked_list_helper.hpp"

// 解法 1 使用迭代
ListNode *removeElements(ListNode *head, int val) {
  ListNode *dummy = new ListNode(-1), *cur = head, *pre = dummy;
  pre->next = cur;

  while (cur) {
    ListNode* next = cur->next;
    if (cur->val == val) {
      pre->next = next;
    } else {
      pre = cur;
    }

    cur = next;
  }

  return dummy->next;
}

// 解法 2 使用遞迴
ListNode *removeElements(ListNode *head, int val) {
  if (head == nullptr)
    return head;

  head->next = removeElements(head->next, val);

  return head->val == val ? head->next : head;
}