// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

#include "../linked_list_helper.hpp"

ListNode *swapPairs(ListNode *head) {
  ListNode *dummy = new ListNode(-1), *pre = dummy;
  dummy->next = head;

  while (pre->next && pre->next->next) {
    ListNode *t = pre->next->next; // 2,3,4
    pre->next->next = t->next; // 1,3,4
    t->next = pre->next; // 2,1,3,4
    pre->next = t; // dummy,2,1,3,4
    pre = t->next;
  }

  return dummy->next;
}

int main() {
  auto t = stringToListNode("[1,2,3,4]");
  auto r = swapPairs(t);

  return 0;
}