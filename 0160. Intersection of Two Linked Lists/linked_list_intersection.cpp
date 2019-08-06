// Write a program to find the node at which the intersection of two singly linked lists begins.

// For example, the following two linked lists:
// https://assets.leetcode.com/uploads/2018/12/13/160_statement.png

// begin to intersect at node c1.

// Example 1:
// https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png

// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
// Output: Reference of the node with value = 8
// Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From
// the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the
// intersected node in A; There are 3 nodes before the intersected node in B.

// Example 2:
// https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png

// Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Reference of the node with value = 2
// Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From
// the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the
// intersected node in A; There are 1 node before the intersected node in B.

// Example 3:
// https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png

// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: null
// Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two
// lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values. Explanation: The two
// lists do not intersect, so return null.

// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

#include "linked_list_helper.hpp"
#include <cmath>

int size(ListNode *node);

// 先把兩個串列變成等長再比較node是否相同
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int alen = size(headA);
  int blen = size(headB);
  int prefix_len = abs(alen - blen); // 取得兩條串列長度差
  ListNode *cur = alen < blen ? headA : headB;
  ListNode *prefix = alen < blen ? headB : headA;

  while (prefix_len > 0) {
    prefix = prefix->next; // 修剪 prefix
    prefix_len--;
  }

  ListNode *res = cur;
  while (cur != prefix) { // 比較 head
    cur = cur->next;
    prefix = prefix->next;
    res = cur;
  }
  return res;
}

int size(ListNode *node) {
  int s = 0;
  ListNode *tmp = node;
  while (tmp != nullptr) {
    tmp = tmp->next;
    s++;
  }
  return s;
}

int main() {
  ListNode *a = new ListNode(1);
  ListNode *b = new ListNode(2);
  ListNode *c = new ListNode(3);
  ListNode *d = new ListNode(4);
  ListNode *e = new ListNode(5);
  ListNode *f = new ListNode(6);
  ListNode *g = new ListNode(7);
  ListNode *h = new ListNode(8);

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;

  f->next = g;
  g->next = h;
  h->next = c;

  auto res = getIntersectionNode(a, f);

  return 0;
}