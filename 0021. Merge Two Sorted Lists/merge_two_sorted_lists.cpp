#include "../linked_list_helper.hpp"

// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes
// of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

// 檢查那條串列當前node值誰比較大，較小的當頭，大的當next
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    if (l1->val > l2->val) {
        ListNode *tmp = l2;

        // 頭的 next 利用遞迴繼續往下處理
        tmp->next = mergeTwoLists(l1, l2->next);
        return tmp;
    } else {
        ListNode *tmp = l1;
        tmp->next = mergeTwoLists(l1->next, l2);
        return tmp;
    }
}