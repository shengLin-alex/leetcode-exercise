
// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

#include "../linked_list_helper.hpp"

// 這邊如同 0021 的算法
ListNode *merge(ListNode *l1, ListNode *l2) {
  if (!l1)
    return l2;
  if (!l2)
    return l1;

  if (l1->val > l2->val) {
    l2->next = merge(l1, l2->next);
    return l2;
  } else {
    l1->next = merge(l2, l1->next);
    return l1;
  }
}

// 利用 merge ListNode 的技巧來達到排序的效果
// 由於是亂序所以必須拆分到最小單位才能進行大小比對
// 以決定誰當頭誰當next
ListNode *sortList(ListNode *head) {
  // 每次都取中間的 node 來處理
  // two pointers fast比slow多走兩步 => 直到fast到底的時候slow就會到中間
  if (!head || !head->next)
    return head;

  ListNode *slow = head, *fast = head, *pre = head;
  while (fast && fast->next) {
    pre = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  pre->next = nullptr; // <- 這個時候 pre 其實是 head->next，如果不設 pre->next = null 會無窮無盡
  return merge(sortList(head), sortList(slow));
}

int main() {
  auto l = stringToListNode("[-1,5,3,4,0]");
  auto r = sortList(l);

  return 0;
}