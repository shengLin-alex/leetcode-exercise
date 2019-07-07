// Given a linked list, remove the nth node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

// Follow up:

// Could you do this in one pass?

#include "../linked_list_helper.hpp"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr) return nullptr;
    ListNode* pre = head;
    ListNode* cur = head;
        
    for (int i = 0; i < n; i++) cur = cur->next; // cur 先走n步
    if (cur == nullptr) return head->next; // 如果走到 nullptr，表示要移除的為 head
        
    while (cur->next != nullptr) {
        cur = cur->next; // cur 非最後一個node則繼續走
        pre = pre->next;
    }
        
    // 此時 pre 為要刪除之 node 前一個
    pre->next = pre->next->next;
        
    return head;
}

int main() {
    ListNode* t = stringToListNode("[1,2,3,4,5]");
    auto r = removeNthFromEnd(t, 2);

    return 0;
}