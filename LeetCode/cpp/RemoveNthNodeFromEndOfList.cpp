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
    // Space Complexity: O(n)
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int pos = -1;

        function<void(ListNode *)> traverse = [&](ListNode *node)
        {
            if (!node)
                return;

            traverse(node->next);
            ++pos;

            if (pos == n)
            {
                node->next = node->next->next;
            }
        };

        traverse(head);
        ++pos;

        return pos == n ? head->next : head;
    }
};