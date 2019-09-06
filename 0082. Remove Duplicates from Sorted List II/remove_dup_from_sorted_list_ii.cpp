// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the
// original list.

// Example 1:

// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Example 2:

// Input: 1->1->1->2->3
// Output: 2->3

#include "../linked_list_helper.hpp"

ListNode *deleteDuplicates(ListNode *head) {
  ListNode *dummy = new ListNode(-1), *pre = dummy;
  dummy->next = head;

  while (pre->next) {
    ListNode *cur = pre->next;
    while(cur->next && cur->next->val == cur->val) {
      cur = cur->next;
    }

    // 此時的 cur 為重複的最後一個節點或是沒有重複保持原先 cur->next(沒有重複的節點)
    if (cur != pre->next) { // 有重複節點出現，略過 cur 接上 cur->next
      pre->next = cur->next;
    } else {
      pre = pre->next;
    }
  }

  return dummy->next;
}