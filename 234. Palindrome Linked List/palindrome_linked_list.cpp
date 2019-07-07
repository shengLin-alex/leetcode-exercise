// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

#include "../linked_list_helper.hpp"
#include <vector>

using namespace std;

bool isPalindrome(ListNode *head)
{
    vector<int> t;
    while (head != nullptr)
    {
        t.push_back(head->val);
        head = head->next;
    }

    int f = 0, e = t.size() - 1;
    while (f < e)
    {
        if (t[f++] != t[e--])
            return false;
    }
    return true;
}