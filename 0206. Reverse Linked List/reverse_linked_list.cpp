
// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively or recursively. Could you implement both?

#include "linked_list_helper.hpp"

// 非常基礎之連結串列反轉
ListNode *reverseList(ListNode *head) {
  ListNode *pre = nullptr;
  ListNode *cur = head;

  while (cur != nullptr) {
    ListNode *next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  return pre;
}