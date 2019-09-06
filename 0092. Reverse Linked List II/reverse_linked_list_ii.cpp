// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:

// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

#include "../linked_list_helper.hpp"

// 利用區間取出起始節點與終點節點
// 並再取出起始前一個節點與終點後一個節點來反轉最後的中間串列
// 須注意的是若 m 為左邊邊界值，表示dummy沒有被更新過，則回傳 dummy->next
// 否則回傳 head
ListNode *reverseBetween(ListNode *head, int m, int n) {
  if (m == n)
    return head;

  ListNode *dummy = new ListNode(-1);
  ListNode *pre = nullptr, *cur = head;
  ListNode *start = nullptr, *pre_start = dummy;
  ListNode *end = nullptr, *after_end = nullptr;
  int ptr = 1;

  while (cur != nullptr) {
    ListNode *next = cur->next;

    if (ptr == m - 1)
      pre_start = cur;
    if (ptr == m)
      start = cur;
    if (ptr == n)
      end = cur;
    if (ptr == n + 1)
      after_end = cur;

    if (m < ptr && ptr <= n)
      cur->next = pre;

    pre = cur;
    cur = next;
    ++ptr;
  }

  pre_start->next = end;
  start->next = after_end;

  return pre_start == dummy ? dummy->next : head;
}

int main() {
  auto l = stringToListNode("[3,5,7,8]");
  auto r = reverseBetween(l, 1, 1);

  return 0;
}