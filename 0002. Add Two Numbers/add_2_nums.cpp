// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
// order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

#include "../linked_list_helper.hpp"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1), *cur = dummy; // 利用 dummy 節點來幫助連結運算結果的新節點
    int carry = 0;

    while (l1 || l2) {
        int val1 = l1 ? l1->val : 0;   // 取 list 1 value
        int val2 = l2 ? l2->val : 0;   // 取 list 2 value
        int sum = val1 + val2 + carry; // 計算總和，注意須計算 carry
        carry = sum / 10;              // 進位為 sum / 10

        cur->next = new ListNode(sum % 10); // 由於每個節點只存一個位數，所以 sum % 10
        cur = cur->next;                    // 移至下一個位置準備算新節點

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    if (carry > 0)
        cur->next = new ListNode(carry); // 若最後一樣有進位則需要再加入一個新 node

    return dummy->next;
}