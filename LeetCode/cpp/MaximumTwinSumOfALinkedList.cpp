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
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        int maxSum = INT_MIN;
        while (slow != NULL)
        {
            maxSum = max(maxSum, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return maxSum;
    }
};