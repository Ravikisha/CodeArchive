/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy, *cur = head;

        // move cur "m-1" steps forward, so it become the mth node
        int i = 1;
        for (; i < left; ++i)
        {
            prev = cur;
            cur = cur->next;
        }

        // rdummy: the previous node of the head of reversed list
        ListNode *rdummy = prev;
        // rtail: the tail of reversed list
        ListNode *rtail = cur;

        // do n-m+1 times, moving "cur" from mth node to (n+1)th node
        // m -> (m-1), (m+1) -> m, ..., n->(n-1)
        for (; i <= right; ++i)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // prev is the tail of reversed list
        rdummy->next = prev;
        // cur is the next node of the tail of reversed list
        rtail->next = cur;

        return dummy->next;
    }
};