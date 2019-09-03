// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3

#include "../linked_list_helper.hpp"

// 利用 two pointer 來幫助移除重複的值
ListNode *deleteDuplicates(ListNode *head) {
  ListNode *prev = nullptr, *cur = head;

  while (cur) {
    if (prev && cur->val == prev->val) {
      // 跳過 cur 將原 cur 的 next 接給 prev 的 next
      prev->next = cur->next;
    } else {
      prev = cur;
    }

    cur = cur->next;
  }

  return head;
}

int main() {
  auto t = stringToListNode("[1,1,2]");
  auto r = deleteDuplicates(t);

  return 0;
}