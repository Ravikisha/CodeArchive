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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *second = head;
        ListNode *initial = head;
        int index = 0;
        while (initial->next != nullptr && index < k - 1)
        {
            initial = initial->next;
            index++;
        }
        second = initial;
        while (second->next != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        int temp = initial->val;
        initial->val = first->val;
        first->val = temp;
        return head;
    }
};